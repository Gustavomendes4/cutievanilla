#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "pico.h"
#include "cascade_face.h"

// Leitor simples de imagem BMP (24-bits) e conversão para escala de cinza
unsigned char* carregar_bmp_gray(const char* filename, int* width, int* height) {
    FILE* f = fopen(filename, "rb");
    if (!f) return NULL;

    unsigned char header[54];
    if (fread(header, 1, 54, f) != 54) {
        fclose(f);
        return NULL;
    }

    if (header[0] != 'B' || header[1] != 'M') {
        fclose(f);
        return NULL;
    }

    *width = *(int*)&header[18];
    *height = *(int*)&header[22];
    int bits_per_pixel = *(short*)&header[28];

    if (bits_per_pixel != 24) {
        printf("Aviso: [%s] Nao e BMP de 24 bits. {%d}\n", filename, bits_per_pixel);
        fclose(f);
        return NULL;
    }

    int w = *width;
    int h = *height;
    int row_padded = (w * 3 + 3) & (~3);

    unsigned char* img_gray = (unsigned char*)malloc(w * h);
    unsigned char* row = (unsigned char*)malloc(row_padded);

    for (int y = h - 1; y >= 0; y--) {
        if (fread(row, 1, row_padded, f) != (size_t)row_padded) {
            free(row);
            free(img_gray);
            fclose(f);
            return NULL;
        }
        for (int x = 0; x < w; x++) {
            unsigned char b = row[x * 3];
            unsigned char g = row[x * 3 + 1];
            unsigned char r = row[x * 3 + 2];

            img_gray[y * w + x] = (unsigned char)(0.299f * r + 0.587f * g + 0.114f * b);
        }
    }

    free(row);
    fclose(f);
    return img_gray;
}

int main(int argc, char** argv) {
    // Valida se o nome da imagem foi informado via argumento
    if (argc < 2) {
        printf("Uso: .\\detector_win.exe <nome_do_arquivo.bmp>\n");
        return 1;
    }

    const char* caminho_imagem = argv[1];
    int width = 0, height = 0;

    unsigned char* pixels = carregar_bmp_gray(caminho_imagem, &width, &height);
    if (!pixels) {
        printf("Erro ao carregar a imagem '%s'.\n", caminho_imagem);
        return 1;
    }

    float rcsq[4 * 1024];
    int max_detections = 1024;

    float min_size = 40.0f;
    float max_size = 1000.0f;
    float scale_factor = 1.1f;
    float stride = 0.1f;

    int num_detections = find_objects(
        rcsq, max_detections,
        (void*)facefinder,
        0.0f,
        pixels, height, width, width,
        scale_factor, stride, min_size, max_size
    );

    num_detections = cluster_detections(rcsq, num_detections);

    printf("\n========================================\n");
    printf("Arquivo: %s (%dx%d px)\n", caminho_imagem, width, height);
    printf("Faces encontradas: %d\n", num_detections);

    for (int i = 0; i < num_detections; ++i) {
        float score = rcsq[4 * i + 3];
        if (score > 12.0f) {
            float r = rcsq[4 * i + 0];
            float c = rcsq[4 * i + 1];
            float s = rcsq[4 * i + 2];

            int x_min = (int)(c - s / 2.0f);
            int y_min = (int)(r - s / 2.0f);
            int tamanho = (int)s;

            printf("  -> Face #%d: X=%d, Y=%d, Tam=%d px | Score=%.2f\n",
                   i + 1, x_min, y_min, tamanho, score);
        }
    }

    free(pixels);
    return 0;
}
