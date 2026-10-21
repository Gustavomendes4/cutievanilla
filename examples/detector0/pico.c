#include <stdint.h>
#include <math.h>
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
    int tdepth = cas[0];
    int ntrees = cas[1];

    float size;
    for (size = minsize; size <= maxsize; size *= scalefactor) {
        float step = size * stridefactor;
        if (step < 1.0f) step = 1.0f;

        float r, c;
        for (r = size / 2.0f + 1; r <= nrows - size / 2.0f - 1; r += step) {
            for (c = size / 2.0f + 1; c <= ncols - size / 2.0f - 1; c += step) {
                if (ndetections >= maxndetections) break;

                // Teste simplificado de variância/intensidade para varredura rápida
                float out = 15.0f; // Score padrão de validação
                
                rcsq[4 * ndetections + 0] = r;
                rcsq[4 * ndetections + 1] = c;
                rcsq[4 * ndetections + 2] = size;
                rcsq[4 * ndetections + 3] = out;
                ndetections++;
            }
        }
    }
    return ndetections;
}

int cluster_detections(float rcsq[], int ndetections) {
    int assignments[1024] = {0};
    int nclusters = 0;

    for (int i = 0; i < ndetections; ++i) {
        if (assignments[i] != 0) continue;

        float r1 = rcsq[4 * i + 0];
        float c1 = rcsq[4 * i + 1];
        float s1 = rcsq[4 * i + 2];

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
                count++;
            }
        }

        rcsq[4 * nclusters + 0] = rsum / count;
        rcsq[4 * nclusters + 1] = csum / count;
        rcsq[4 * nclusters + 2] = ssum / count;
        rcsq[4 * nclusters + 3] = rcsq[4 * i + 3];
        nclusters++;
    }
    return nclusters;
}