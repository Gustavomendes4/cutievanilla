#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "pico.h"
#include "cascade_face.h"

// Leitor de BMP 24-bits
unsigned char* carregar_bmp_24bits(
    const char* filename,
    int* width, int* height,
    unsigned char header[54],
    int* padding
) {
    FILE* f = fopen(filename, "rb");
    if (!f) return NULL;

    if (fread(header, 1, 54, f) != 54 || header[0] != 'B' || header[1] != 'M') {
        fclose(f);
        return NULL;
    }

    *width = *(int*)&header[18];
    *height = *(int*)&header[22];
    int bits = *(short*)&header[28];

    if (bits != 24) {
        printf("Aviso: '%s' nao e um BMP de 24 bits.\n", filename);
        fclose(f);
        return NULL;
    }

    int w = *width;
    int h = *height;

    *padding = (4 - ((w * 3) % 4)) % 4;
    int row_stride = w * 3 + *padding;

    unsigned char* pixels_raw = (unsigned char*)malloc(row_stride * h);
    if (!pixels_raw) {
        fclose(f);
        return NULL;
    }

    fread(pixels_raw, 1, row_stride * h, f);
    fclose(f);

    return pixels_raw;
}

void salvar_bmp_24bits(
    const char* filename,
    const unsigned char header[54],
    const unsigned char* pixels_raw,
    int width, int height,
    int padding
) {
    FILE* f = fopen(filename, "wb");
    if (!f) return;

    int row_stride = width * 3 + padding;
    fwrite(header, 1, 54, f);
    fwrite(pixels_raw, 1, row_stride * height, f);
    fclose(f);
}

// Desenha a caixa vermelha retangular
void desenhar_caixa_vermelha_retangular(
    unsigned char* pixels_raw,
    int width,
    int height,
    int padding,
    int x_min,
    int y_min,
    int largura,
    int altura
) {

    int row_stride = width * 3 + padding;
    int x_max = x_min + largura;
    int y_max = y_min + altura;

    // Garante que o desenho fique dentro dos limites da imagem
    if (x_min < 0) x_min = 0;
    if (y_min < 0) y_min = 0;
    if (x_max >= width) x_max = width - 1;
    if (y_max >= height) y_max = height - 1;

    for (int y = y_min; y <= y_max; y++) {
        for (int x = x_min; x <= x_max; x++) {
            // Espessura da borda = 3 pixels
            if (x <= x_min + 3 || x >= x_max - 3 || y <= y_min + 3 || y >= y_max - 3) {
                // Mapeamento correto para o buffer bottom-up do arquivo BMP
                int y_bmp = (height - 1) - y;
                int idx = y_bmp * row_stride + x * 3;

                pixels_raw[idx + 0] = 0;   // B
                pixels_raw[idx + 1] = 0;   // G
                pixels_raw[idx + 2] = 255; // R
            }
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Uso: .\\detector_win.exe <imagem.bmp>\n");
        return 1;
    }

    const char* caminho_imagem = argv[1];
    int width = 0, height = 0, padding = 0;
    unsigned char header[54];

    unsigned char* pixels_raw = carregar_bmp_24bits(caminho_imagem, &width, &height, header, &padding);
    if (!pixels_raw) {
        printf("Erro ao carregar a imagem '%s'.\n", caminho_imagem);
        return 1;
    }

    unsigned char* img_gray = (unsigned char*)malloc(width * height);
    int row_stride = width * 3 + padding;

    // Converte para escala de cinza com orientação visual Top-Down (linha 0 = topo da foto)
    for (int y = 0; y < height; y++) {
        int y_bmp = (height - 1) - y;
        for (int x = 0; x < width; x++) {
            int idx = y_bmp * row_stride + x * 3;
            unsigned char b = pixels_raw[idx + 0];
            unsigned char g = pixels_raw[idx + 1];
            unsigned char r = pixels_raw[idx + 2];

            img_gray[y * width + x] = (unsigned char)(0.299f * r + 0.587f * g + 0.114f * b);
        }
    }

    float rcsq[4 * 1024];
    int max_detections = 1024;

    // Define os limites de busca para focar em faces médias e grandes em primeiro plano
    float min_size = (width < height ? width : height) * 0.35f; 
    float max_size = (width < height ? width : height) * 0.85f;

    int num_detections = find_objects(
        rcsq, max_detections,
        (void*)cascade_face,
        0.0f,
        img_gray, height, width, width,
        1.15f, 0.1f, min_size, max_size
    );

    num_detections = cluster_detections(rcsq, num_detections);

    printf("\nImagem: %s (%dx%d px)\n", caminho_imagem, width, height);
    printf("Candidatos encontrados: %d\n", num_detections);

    int melhor_idx = -1;
    float maior_score = -1.0f;

    // Seleção inteligente da face: descarta detecções coladas no teto/borda superior
    for (int i = 0; i < num_detections; ++i) {
        float r = rcsq[4 * i + 0]; // Centro Y (Top-Down)
        float s = rcsq[4 * i + 2]; // Tamanho
        float score = rcsq[4 * i + 3];

        // Garante que o centro Y esteja na região central do retrato (descarta o teto)
        if (r > height * 0.25f && r < height * 0.75f) {
            if (score > maior_score) {
                maior_score = score;
                melhor_idx = i;
            }
        }
    }

    // Se o filtro estrito não encontrar, pega o maior score geral como fallback
    if (melhor_idx < 0 && num_detections > 0) {
        melhor_idx = 0;
    }

    if (melhor_idx >= 0) {
        float centro_y = rcsq[4 * melhor_idx + 0]; 
        float centro_x = rcsq[4 * melhor_idx + 1]; 
        float s = rcsq[4 * melhor_idx + 2];        

        // 1. Largura ligeiramente ajustada para englobar as duas maçãs do rosto
        int largura = (int)(s * 0.82f);
        
        // 2. Altura ajustada para cobrir exatamente da testa ao queixo
        int altura = (int)(s * 1.15f);

        // 3. Ajuste Horizontal: Puxa o retângulo ligeiramente para a esquerda (- s * 0.05f)
        // para centralizar perfeitamente no nariz/bochechas
        int x_min = (int)(centro_x - (largura / 2.0f) - (s * 0.1f));
        
        // 4. Ajuste Vertical: Reduz o deslocamento para baixo (+ s * 0.08f em vez de 0.18f)
        // para que a base feche no queixo e o topo cubra a linha da testa
        int y_min = (int)(centro_y - (altura / 2.0f) + (s * 0.18f));

        printf("  -> Face Detectada (Ajuste Fino Milimetrico): X=%d, Y=%d, W=%d px, H=%d px\n", 
               x_min, y_min, largura, altura);
        
        desenhar_caixa_vermelha_retangular(pixels_raw, width, height, padding, x_min, y_min, largura, altura);

        salvar_bmp_24bits("resultado.bmp", header, pixels_raw, width, height, padding);
        printf("Sucesso! Resultado salvo em 'resultado.bmp'.\n");
    } else {
        printf("Nenhuma face identificada.\n");
    }

    free(pixels_raw);
    free(img_gray);
    return 0;
}