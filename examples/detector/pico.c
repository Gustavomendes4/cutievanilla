#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include "pico.h"

int find_objects(
    float rcsq[],
    int maxndetections,
    void* cascade,
    float angle,
    void* pixels,
    int nrows,
    int ncols,
    int ldim,
    float scalefactor,
    float stridefactor,
    float minsize,
    float maxsize
) {
    int ndetections = 0;
    uint8_t* py = (uint8_t*)pixels;

    int32_t* cas = (int32_t*)cascade;
    int tdepth = cas[2];
    int ntrees = cas[3];
    int8_t* pcode = (int8_t*)&cas[4];

    for (float size = minsize; size <= maxsize; size *= scalefactor) {

        float step = size * stridefactor;
        if (step < 2.0f) step = 2.0f;

        for (float r = size / 2.0f + 1; r <= nrows - size / 2.0f - 1; r += step) {
            for (float c = size / 2.0f + 1; c <= ncols - size / 2.0f - 1; c += step) {
                if (ndetections >= maxndetections) break;

                // Executa a validação de cascata de decisão AdaBoost/PICO
                float score = 0.0f;
                int8_t* p = pcode;

                for (int i = 0; i < ntrees; ++i) {
                    int idx = 1;
                    for (int j = 0; j < tdepth; ++j) {
                        int r1 = (int)(r + (p[4 * idx + 0] * size) / 256.0f);
                        int c1 = (int)(c + (p[4 * idx + 1] * size) / 256.0f);
                        int r2 = (int)(r + (p[4 * idx + 2] * size) / 256.0f);
                        int c2 = (int)(c + (p[4 * idx + 3] * size) / 256.0f);

                        if (r1 < 0 || r1 >= nrows || c1 < 0 || c1 >= ncols ||
                            r2 < 0 || r2 >= nrows || c2 < 0 || c2 >= ncols) {
                            idx = 2 * idx;
                        } else {
                            uint8_t p1 = py[r1 * ldim + c1];
                            uint8_t p2 = py[r2 * ldim + c2];
                            idx = 2 * idx + (p1 <= p2);
                        }
                    }
                    float* leaf_weights = (float*)(p + (1 << (tdepth + 1)) * 4);
                    score += leaf_weights[idx % (1 << tdepth)];
                    p += (1 << (tdepth + 1)) * 4 + (1 << tdepth) * sizeof(float);
                }

                if (score > 1.5f) { // Limiar de confiança da cascata
                    rcsq[4 * ndetections + 0] = r;
                    rcsq[4 * ndetections + 1] = c;
                    rcsq[4 * ndetections + 2] = size;
                    rcsq[4 * ndetections + 3] = score;
                    ndetections++;
                }
            }
        }
    }
    
    return ndetections;
}

int cluster_detections(float rcsq[], int ndetections) {
    if (ndetections <= 0) return 0;

    int* assignments = (int*)calloc(ndetections, sizeof(int));
    int nclusters = 0;

    for (int i = 0; i < ndetections; ++i) {
        if (assignments[i] != 0) continue;

        float r1 = rcsq[4 * i + 0];
        float c1 = rcsq[4 * i + 1];
        float s1 = rcsq[4 * i + 2];
        float max_score = rcsq[4 * i + 3];

        float rsum = r1, csum = c1, ssum = s1;
        int count = 1;

        for (int j = i + 1; j < ndetections; ++j) {
            float r2 = rcsq[4 * j + 0];
            float c2 = rcsq[4 * j + 1];
            float s2 = rcsq[4 * j + 2];

            float dist = sqrtf((r1 - r2) * (r1 - r2) + (c1 - c2) * (c1 - c2));
            if (dist < 0.25f * (s1 + s2)) {
                assignments[j] = 1;
                rsum += r2;
                csum += c2;
                ssum += s2;
                if (rcsq[4 * j + 3] > max_score) max_score = rcsq[4 * j + 3];
                count++;
            }
        }

        // Filtra para manter somente agrupamentos consolidados (rejeita ruídos isolados no cabelo/fundo)
        if (count >= 6) {
            rcsq[4 * nclusters + 0] = rsum / count;
            rcsq[4 * nclusters + 1] = csum / count;
            rcsq[4 * nclusters + 2] = ssum / count;
            rcsq[4 * nclusters + 3] = max_score;
            nclusters++;
        }
    }

    free(assignments);
    return nclusters;
}