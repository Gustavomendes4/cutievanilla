#ifndef CASCADE_FACE_H
#define CASCADE_FACE_H

#include <stdint.h>

// Estrutura do classificador PICO para detecção facial
// [profundidade da arvore, numero de arvores, dados...]
static const uint32_t facefinder[] = {
    6,      // Profundidade da árvore (tdepth)
    1,      // Número de árvores de decisão (ntrees)
    0, 0,   // Reservado
    
    // Parâmetros de teste de intensidade de pixels
    -12, -12, 12, 12,
    -6,  -6,  6,  6,
    -3,  -3,  3,  3,
    0,    0,  0,  0,
    
    // Pesos das folhas
    0x3f800000, 0xbf800000
};

#endif