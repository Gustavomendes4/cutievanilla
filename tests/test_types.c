
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "cutievanilla.h"
#include "cutievanilla/type.h"

typedef union _Operator{
    uint8_t  u8;
    int8_t   i8;
    uint16_t u16;
    int16_t  i16;
    uint32_t u32;
    int32_t  i32;
    
    float  f32;
    double f64;

}Operator;

typedef struct _TestCase{

    int index;

    CVType type;

    TypeError (*operation)(CVType, void*, const void*, const void*);

    bool isEquals;
    
    Operator a;

    Operator b;

    Operator result;
    

}TestCase;


static const TestCase cases_u8[] = {

    /* Add */
    { 0, CV_UINT8, cv_type_add, true, .a.u8 = 10, .b.u8 = 20, .result.u8 = 30},
    { 1, CV_UINT8, cv_type_add, true, .a.u8 = 24, .b.u8 = 20, .result.u8 = 44},
    { 2, CV_UINT8, cv_type_add, true, .a.u8 = 250, .b.u8 = 5, .result.u8 = 255},
    { 3, CV_UINT8, cv_type_add, true, .a.u8 = 250, .b.u8 = 6, .result.u8 = 0},
    { 4, CV_UINT8, cv_type_add, true, .a.u8 = 0, .b.u8 = 1, .result.u8 = 1},
    { 5, CV_UINT8, cv_type_add, true, .a.u8 = 10, .b.u8 = 200, .result.u8 = 210},
    { 6, CV_UINT8, cv_type_add, false, .a.u8 = 40, .b.u8 = 36, .result.u8 = 74},
    { 7, CV_UINT8, cv_type_add, false, .a.u8 = 40, .b.u8 = 10, .result.u8 = 2},    
    { 8, CV_UINT8, cv_type_add, false, .a.u8 = 80, .b.u8 = 10, .result.u8 = 91},
    { 9, CV_UINT8, cv_type_add, false, .a.u8 = 200, .b.u8 = 55, .result.u8 = 250},

    /* SUB */
    { 10, CV_UINT8, cv_type_sub, true, .a.u8 = 10, .b.u8 = 5, .result.u8 = 5},
    { 11, CV_UINT8, cv_type_sub, true, .a.u8 = 24, .b.u8 = 20, .result.u8 = 4},
    { 12, CV_UINT8, cv_type_sub, true, .a.u8 = 250, .b.u8 = 5, .result.u8 = 245},
    { 13, CV_UINT8, cv_type_sub, true, .a.u8 = 250, .b.u8 = 250, .result.u8 = 0},
    { 14, CV_UINT8, cv_type_sub, true, .a.u8 = 0, .b.u8 = 1, .result.u8 = 255},    
    { 15, CV_UINT8, cv_type_sub, true, .a.u8 = 10, .b.u8 = 200, .result.u8 = 66},
    { 16, CV_UINT8, cv_type_sub, true, .a.u8 = 1, .b.u8 = 0, .result.u8 = 1},
    { 17, CV_UINT8, cv_type_sub, false, .a.u8 = 140, .b.u8 = 10, .result.u8 = 120},
    { 18, CV_UINT8, cv_type_sub, false, .a.u8 = 180, .b.u8 = 180, .result.u8 = 1},
    { 19, CV_UINT8, cv_type_sub, false, .a.u8 = 200, .b.u8 = 55, .result.u8 = 250},
    
    /* MUL */
    { 20, CV_UINT8, cv_type_mul, true, .a.u8 = 20, .b.u8 = 10, .result.u8 = 200},
    { 21, CV_UINT8, cv_type_mul, true, .a.u8 = 20, .b.u8 = 5, .result.u8 = 100},
    { 22, CV_UINT8, cv_type_mul, true, .a.u8 = 100, .b.u8 = 0, .result.u8 = 0},
    { 23, CV_UINT8, cv_type_mul, true, .a.u8 = 4, .b.u8 = 25, .result.u8 = 100},
    { 24, CV_UINT8, cv_type_mul, true, .a.u8 = 70, .b.u8 = 3, .result.u8 = 210},
    { 25, CV_UINT8, cv_type_mul, true, .a.u8 = 35, .b.u8 = 2, .result.u8 = 70},
    { 26, CV_UINT8, cv_type_mul, false, .a.u8 = 200, .b.u8 = 55, .result.u8 = 250},
    { 27, CV_UINT8, cv_type_mul, false, .a.u8 = 1, .b.u8 = 1, .result.u8 = 2},
    { 28, CV_UINT8, cv_type_mul, false, .a.u8 = 66, .b.u8 = 2, .result.u8 = 166},
    { 29, CV_UINT8, cv_type_mul, false, .a.u8 = 22, .b.u8 = 2, .result.u8 = 40},
    { 30, CV_UINT8, cv_type_mul, true, .a.u8 = 5, .b.u8 = 5, .result.u8 = 25},
    
    /* DIV */
    { 40, CV_UINT8, cv_type_div, true, .a.u8 = 200, .b.u8 = 2, .result.u8 = 100},
    { 41, CV_UINT8, cv_type_div, true, .a.u8 = 250, .b.u8 = 2, .result.u8 = 125},
    { 42, CV_UINT8, cv_type_div, true, .a.u8 = 0, .b.u8 = 2, .result.u8 = 0},
    { 43, CV_UINT8, cv_type_div, true, .a.u8 = 10, .b.u8 = 5, .result.u8 = 2},
    { 44, CV_UINT8, cv_type_div, true, .a.u8 = 2, .b.u8 = 1, .result.u8 = 2},
    { 45, CV_UINT8, cv_type_div, true, .a.u8 = 251, .b.u8 = 2, .result.u8 = 125},
    { 46, CV_UINT8, cv_type_div, false, .a.u8 = 200, .b.u8 = 50, .result.u8 = 10},
    { 47, CV_UINT8, cv_type_div, false, .a.u8 = 60, .b.u8 = 6, .result.u8 = 6},
    { 48, CV_UINT8, cv_type_div, false, .a.u8 = 30, .b.u8 = 2, .result.u8 = 20},
    { 49, CV_UINT8, cv_type_div, false, .a.u8 = 2, .b.u8 = 2, .result.u8 = 0},
    

    {-1}
};

static const TestCase cases_i8[] = {

    /* === ADD (Adição) === */
    /* Casos Normais Positivos e Negativos */
    {  0, CV_INT8, cv_type_add, true,  .a.i8 = 10,   .b.i8 = 20,   .result.i8 = 30 },
    {  1, CV_INT8, cv_type_add, true,  .a.i8 = -10,  .b.i8 = -20,  .result.i8 = -30 },
    {  2, CV_INT8, cv_type_add, true,  .a.i8 = -50,  .b.i8 = 50,   .result.i8 = 0 },

    /* Fronteiras (Bordas) */
    {  3, CV_INT8, cv_type_add, true,  .a.i8 = 126,  .b.i8 = 1,    .result.i8 = 127 },  /* Borda superior: INT8_MAX */
    {  4, CV_INT8, cv_type_add, true,  .a.i8 = -127, .b.i8 = -1,   .result.i8 = -128 }, /* Borda inferior: INT8_MIN */
    {  5, CV_INT8, cv_type_add, true,  .a.i8 = 127,  .b.i8 = 0,    .result.i8 = 127 },  /* Elemento neutro na borda */
    {  6, CV_INT8, cv_type_add, true,  .a.i8 = -128, .b.i8 = 0,    .result.i8 = -128 },

    /* Overflow / Underflow com Wraparound (Dois complementos) */
    {  7, CV_INT8, cv_type_add, true,  .a.i8 = 127,  .b.i8 = 1,    .result.i8 = -128 }, /* Overflow: 127 + 1 = -128 */
    {  8, CV_INT8, cv_type_add, true,  .a.i8 = 100,  .b.i8 = 30,   .result.i8 = -126 }, /* Overflow: 130 -> -126 */
    {  9, CV_INT8, cv_type_add, true,  .a.i8 = -128, .b.i8 = -1,   .result.i8 = 127 },  /* Underflow: -128 - 1 = 127 */

    /* Testes Falhos (Expectativa false) */
    { 10, CV_INT8, cv_type_add, false, .a.i8 = 10,   .b.i8 = 20,   .result.i8 = 31 },   /* Resultado incorreto */
    { 11, CV_INT8, cv_type_add, false, .a.i8 = -10,  .b.i8 = -20,  .result.i8 = -40 },  /* Resultado incorreto */


    /* === SUB (Subtração) === */
    /* Casos Normais */
    { 12, CV_INT8, cv_type_sub, true,  .a.i8 = 20,   .b.i8 = 10,   .result.i8 = 10 },
    { 13, CV_INT8, cv_type_sub, true,  .a.i8 = 10,   .b.i8 = 20,   .result.i8 = -10 },
    { 14, CV_INT8, cv_type_sub, true,  .a.i8 = -10,  .b.i8 = -20,  .result.i8 = 10 },

    /* Fronteiras (Bordas) */
    { 15, CV_INT8, cv_type_sub, true,  .a.i8 = 127,  .b.i8 = 127,  .result.i8 = 0 },
    { 16, CV_INT8, cv_type_sub, true,  .a.i8 = -128, .b.i8 = -128, .result.i8 = 0 },
    { 17, CV_INT8, cv_type_sub, true,  .a.i8 = 127,  .b.i8 = 1,    .result.i8 = 126 },
    { 18, CV_INT8, cv_type_sub, true,  .a.i8 = -127, .b.i8 = 1,    .result.i8 = -128 },

    /* Overflow / Underflow */
    { 19, CV_INT8, cv_type_sub, true,  .a.i8 = 127,  .b.i8 = -1,   .result.i8 = -128 }, /* Overflow: 127 - (-1) = 128 -> -128 */
    { 20, CV_INT8, cv_type_sub, true,  .a.i8 = -128, .b.i8 = 1,    .result.i8 = 127 },  /* Underflow: -128 - 1 = -129 -> 127 */

    /* Testes Falhos */
    { 21, CV_INT8, cv_type_sub, false, .a.i8 = 1,    .b.i8 = 1,    .result.i8 = 2 },


    /* === MUL (Multiplicação) === */
    /* Casos Normais */
    { 22, CV_INT8, cv_type_mul, true,  .a.i8 = 5,    .b.i8 = 4,    .result.i8 = 20 },
    { 23, CV_INT8, cv_type_mul, true,  .a.i8 = -5,   .b.i8 = 4,    .result.i8 = -20 },
    { 24, CV_INT8, cv_type_mul, true,  .a.i8 = -5,   .b.i8 = -4,   .result.i8 = 20 },
    { 25, CV_INT8, cv_type_mul, true,  .a.i8 = 127,  .b.i8 = 0,    .result.i8 = 0 },

    /* Fronteiras (Bordas) */
    { 26, CV_INT8, cv_type_mul, true,  .a.i8 = 127,  .b.i8 = 1,    .result.i8 = 127 },
    { 27, CV_INT8, cv_type_mul, true,  .a.i8 = -128, .b.i8 = 1,    .result.i8 = -128 },
    { 28, CV_INT8, cv_type_mul, true,  .a.i8 = 63,   .b.i8 = 2,    .result.i8 = 126 },
    { 29, CV_INT8, cv_type_mul, true,  .a.i8 = -64,  .b.i8 = 2,    .result.i8 = -128 },

    /* Overflow (Truncamento de 8 bits) */
    { 30, CV_INT8, cv_type_mul, true,  .a.i8 = 16,   .b.i8 = 10,   .result.i8 = -96 }, /* 160 % 256 = 160 -> -96 em int8 */
    { 31, CV_INT8, cv_type_mul, true,  .a.i8 = -128, .b.i8 = -1,   .result.i8 = -128 },/* Custo de borda: -128 * -1 = 128 -> -128 */

    /* Testes Falhos */
    { 32, CV_INT8, cv_type_mul, false, .a.i8 = 5,    .b.i8 = 5,    .result.i8 = 30 },


    /* === DIV (Divisão) === */
    /* Casos Normais */
    { 33, CV_INT8, cv_type_div, true,  .a.i8 = 100,  .b.i8 = 2,    .result.i8 = 50 },
    { 34, CV_INT8, cv_type_div, true,  .a.i8 = -100, .b.i8 = 2,    .result.i8 = -50 },
    { 35, CV_INT8, cv_type_div, true,  .a.i8 = -100, .b.i8 = -2,   .result.i8 = 50 },
    { 36, CV_INT8, cv_type_div, true,  .a.i8 = 7,    .b.i8 = 2,    .result.i8 = 3 },  /* Divisão inteira (truncamento) */

    /* Fronteiras (Bordas) */
    { 37, CV_INT8, cv_type_div, true,  .a.i8 = 127,  .b.i8 = 1,    .result.i8 = 127 },
    { 38, CV_INT8, cv_type_div, true,  .a.i8 = 127,  .b.i8 = 127,  .result.i8 = 1 },
    { 39, CV_INT8, cv_type_div, true,  .a.i8 = -128, .b.i8 = 1,    .result.i8 = -128 },
    { 40, CV_INT8, cv_type_div, true,  .a.i8 = -128, .b.i8 = -128, .result.i8 = 1 },
    { 41, CV_INT8, cv_type_div, true,  .a.i8 = 0,    .b.i8 = 127,  .result.i8 = 0 },

    /* Caso Especial de Overflow de Divisão */
    { 42, CV_INT8, cv_type_div, true,  .a.i8 = -128, .b.i8 = -1,   .result.i8 = -128 },/* -128 / -1 = 128 (estoura int8 -> wraparound pra -128) */

    /* Testes Falhos */
    { 43, CV_INT8, cv_type_div, false, .a.i8 = 10,   .b.i8 = 2,    .result.i8 = 6 },

    {-1}
};

static const TestCase cases_u16[] = {

    /* === ADD (Adição) === */
    {  0, CV_UINT16, cv_type_add, true,  .a.u16 = 1000,  .b.u16 = 2000,  .result.u16 = 3000 },
    {  1, CV_UINT16, cv_type_add, true,  .a.u16 = 0,     .b.u16 = 0,     .result.u16 = 0 },
    {  2, CV_UINT16, cv_type_add, true,  .a.u16 = 65534, .b.u16 = 1,     .result.u16 = 65535 }, /* UINT16_MAX */
    {  3, CV_UINT16, cv_type_add, true,  .a.u16 = 65535, .b.u16 = 1,     .result.u16 = 0 },     /* Overflow: Wraparound */
    {  4, CV_UINT16, cv_type_add, true,  .a.u16 = 60000, .b.u16 = 10000, .result.u16 = 4464 },  /* 70000 % 65536 = 4464 */
    {  5, CV_UINT16, cv_type_add, false, .a.u16 = 1000,  .b.u16 = 2000,  .result.u16 = 3001 },

    /* === SUB (Subtração) === */
    {  6, CV_UINT16, cv_type_sub, true,  .a.u16 = 5000,  .b.u16 = 2000,  .result.u16 = 3000 },
    {  7, CV_UINT16, cv_type_sub, true,  .a.u16 = 65535, .b.u16 = 65535, .result.u16 = 0 },
    {  8, CV_UINT16, cv_type_sub, true,  .a.u16 = 0,     .b.u16 = 1,     .result.u16 = 65535 }, /* Underflow: Wraparound */
    {  9, CV_UINT16, cv_type_sub, true,  .a.u16 = 100,   .b.u16 = 200,   .result.u16 = 65436 }, /* 100 - 200 + 65536 */
    { 10, CV_UINT16, cv_type_sub, false, .a.u16 = 10,    .b.u16 = 5,     .result.u16 = 0 },

    /* === MUL (Multiplicação) === */
    { 11, CV_UINT16, cv_type_mul, true,  .a.u16 = 200,   .b.u16 = 300,   .result.u16 = 60000 },
    { 12, CV_UINT16, cv_type_mul, true,  .a.u16 = 65535, .b.u16 = 1,     .result.u16 = 65535 },
    { 13, CV_UINT16, cv_type_mul, true,  .a.u16 = 65535, .b.u16 = 0,     .result.u16 = 0 },
    { 14, CV_UINT16, cv_type_mul, true,  .a.u16 = 1000,  .b.u16 = 100,   .result.u16 = 34464 }, /* Overflow: 100000 % 65536 */
    { 15, CV_UINT16, cv_type_mul, false, .a.u16 = 10,    .b.u16 = 10,    .result.u16 = 90 },

    /* === DIV (Divisão) === */
    { 16, CV_UINT16, cv_type_div, true,  .a.u16 = 60000, .b.u16 = 300,   .result.u16 = 200 },
    { 17, CV_UINT16, cv_type_div, true,  .a.u16 = 65535, .b.u16 = 1,     .result.u16 = 65535 },
    { 18, CV_UINT16, cv_type_div, true,  .a.u16 = 65535, .b.u16 = 65535, .result.u16 = 1 },
    { 19, CV_UINT16, cv_type_div, true,  .a.u16 = 5,     .b.u16 = 2,     .result.u16 = 2 },     /* Truncamento inteiro */
    { 20, CV_UINT16, cv_type_div, true,  .a.u16 = 0,     .b.u16 = 65535, .result.u16 = 0 },
    { 21, CV_UINT16, cv_type_div, false, .a.u16 = 100,   .b.u16 = 10,    .result.u16 = 5 },

    {-1}
};

static const TestCase cases_i16[] = {

    /* === ADD (Adição) === */
    {  0, CV_INT16, cv_type_add, true,  .a.i16 = 10000,  .b.i16 = 20000,  .result.i16 = 30000 },
    {  1, CV_INT16, cv_type_add, true,  .a.i16 = -10000, .b.i16 = -20000, .result.i16 = -30000 },
    {  2, CV_INT16, cv_type_add, true,  .a.i16 = 32766,  .b.i16 = 1,      .result.i16 = 32767 },  /* INT16_MAX */
    {  3, CV_INT16, cv_type_add, true,  .a.i16 = -32767, .b.i16 = -1,     .result.i16 = -32768 }, /* INT16_MIN */
    {  4, CV_INT16, cv_type_add, true,  .a.i16 = 32767,  .b.i16 = 1,      .result.i16 = -32768 }, /* Overflow */
    {  5, CV_INT16, cv_type_add, true,  .a.i16 = -32768, .b.i16 = -1,     .result.i16 = 32767 },  /* Underflow */
    {  6, CV_INT16, cv_type_add, false, .a.i16 = 100,    .b.i16 = 200,    .result.i16 = 301 },

    /* === SUB (Subtração) === */
    {  7, CV_INT16, cv_type_sub, true,  .a.i16 = 20000,  .b.i16 = 10000,  .result.i16 = 10000 },
    {  8, CV_INT16, cv_type_sub, true,  .a.i16 = -32768, .b.i16 = -32768, .result.i16 = 0 },
    {  9, CV_INT16, cv_type_sub, true,  .a.i16 = 32767,  .b.i16 = -1,     .result.i16 = -32768 }, /* Overflow: 32767 - (-1) */
    { 10, CV_INT16, cv_type_sub, true,  .a.i16 = -32768, .b.i16 = 1,      .result.i16 = 32767 },  /* Underflow */
    { 11, CV_INT16, cv_type_sub, false, .a.i16 = 100,    .b.i16 = 50,     .result.i16 = 20 },

    /* === MUL (Multiplicação) === */
    { 12, CV_INT16, cv_type_mul, true,  .a.i16 = 100,    .b.i16 = 300,    .result.i16 = 30000 },
    { 13, CV_INT16, cv_type_mul, true,  .a.i16 = -100,   .b.i16 = 300,    .result.i16 = -30000 },
    { 14, CV_INT16, cv_type_mul, true,  .a.i16 = 32767,  .b.i16 = 1,      .result.i16 = 32767 },
    { 15, CV_INT16, cv_type_mul, true,  .a.i16 = -32768, .b.i16 = 1,      .result.i16 = -32768 },
    { 16, CV_INT16, cv_type_mul, true,  .a.i16 = -32768, .b.i16 = -1,     .result.i16 = -32768 }, /* Overflow de borda */
    { 17, CV_INT16, cv_type_mul, false, .a.i16 = 10,     .b.i16 = 10,     .result.i16 = -100 },

    /* === DIV (Divisão) === */
    { 18, CV_INT16, cv_type_div, true,  .a.i16 = 30000,  .b.i16 = 3,      .result.i16 = 10000 },
    { 19, CV_INT16, cv_type_div, true,  .a.i16 = -30000, .b.i16 = 3,      .result.i16 = -10000 },
    { 20, CV_INT16, cv_type_div, true,  .a.i16 = -32768, .b.i16 = 1,      .result.i16 = -32768 },
    { 21, CV_INT16, cv_type_div, true,  .a.i16 = -32768, .b.i16 = -1,     .result.i16 = -32768 }, /* INT16_MIN / -1 estoura tipo */
    { 22, CV_INT16, cv_type_div, false, .a.i16 = 100,    .b.i16 = 2,      .result.i16 = 40 },

    {-1}
};

static const TestCase cases_u32[] = {

    /* === ADD (Adição) === */
    {  0, CV_UINT32, cv_type_add, true,  .a.u32 = 1000000U,    .b.u32 = 2000000U,    .result.u32 = 3000000U },
    {  1, CV_UINT32, cv_type_add, true,  .a.u32 = 4294967294U, .b.u32 = 1U,          .result.u32 = 4294967295U }, /* UINT32_MAX */
    {  2, CV_UINT32, cv_type_add, true,  .a.u32 = 4294967295U, .b.u32 = 1U,          .result.u32 = 0U },          /* Overflow */
    {  3, CV_UINT32, cv_type_add, false, .a.u32 = 100U,        .b.u32 = 200U,        .result.u32 = 301U },

    /* === SUB (Subtração) === */
    {  4, CV_UINT32, cv_type_sub, true,  .a.u32 = 5000000U,    .b.u32 = 2000000U,    .result.u32 = 3000000U },
    {  5, CV_UINT32, cv_type_sub, true,  .a.u32 = 4294967295U, .b.u32 = 4294967295U, .result.u32 = 0U },
    {  6, CV_UINT32, cv_type_sub, true,  .a.u32 = 0U,          .b.u32 = 1U,          .result.u32 = 4294967295U }, /* Underflow */
    {  7, CV_UINT32, cv_type_sub, false, .a.u32 = 500U,        .b.u32 = 200U,        .result.u32 = 100U },

    /* === MUL (Multiplicação) === */
    {  8, CV_UINT32, cv_type_mul, true,  .a.u32 = 10000U,      .b.u32 = 10000U,      .result.u32 = 100000000U },
    {  9, CV_UINT32, cv_type_mul, true,  .a.u32 = 4294967295U, .b.u32 = 1U,          .result.u32 = 4294967295U },
    { 10, CV_UINT32, cv_type_mul, true,  .a.u32 = 4294967295U, .b.u32 = 0U,          .result.u32 = 0U },
    { 11, CV_UINT32, cv_type_mul, true,  .a.u32 = 65537U,      .b.u32 = 65537U,      .result.u32 = 131073U },     /* Overflow 32-bit */
    { 12, CV_UINT32, cv_type_mul, false, .a.u32 = 1000U,       .b.u32 = 1000U,       .result.u32 = 100000U },

    /* === DIV (Divisão) === */
    { 13, CV_UINT32, cv_type_div, true,  .a.u32 = 100000000U,  .b.u32 = 10000U,      .result.u32 = 10000U },
    { 14, CV_UINT32, cv_type_div, true,  .a.u32 = 4294967295U, .b.u32 = 1U,          .result.u32 = 4294967295U },
    { 15, CV_UINT32, cv_type_div, true,  .a.u32 = 7U,          .b.u32 = 2U,          .result.u32 = 3U },          /* Truncamento */
    { 16, CV_UINT32, cv_type_div, false, .a.u32 = 1000U,       .b.u32 = 10U,         .result.u32 = 99U },

    {-1}
};

static const TestCase cases_i32[] = {

    /* === ADD (Adição) === */
    {  0, CV_INT32, cv_type_add, true,  .a.i32 = 1000000,     .b.i32 = 2000000,     .result.i32 = 3000000 },
    {  1, CV_INT32, cv_type_add, true,  .a.i32 = -1000000,    .b.i32 = -2000000,    .result.i32 = -3000000 },
    {  2, CV_INT32, cv_type_add, true,  .a.i32 = 2147483646,  .b.i32 = 1,           .result.i32 = 2147483647 },  /* INT32_MAX */
    {  3, CV_INT32, cv_type_add, true,  .a.i32 = -2147483647, .b.i32 = -1,          .result.i32 = -2147483648 }, /* INT32_MIN */
    {  4, CV_INT32, cv_type_add, true,  .a.i32 = 2147483647,  .b.i32 = 1,           .result.i32 = -2147483648 }, /* Overflow */
    {  5, CV_INT32, cv_type_add, true,  .a.i32 = -2147483648, .b.i32 = -1,          .result.i32 = 2147483647 },  /* Underflow */
    {  6, CV_INT32, cv_type_add, false, .a.i32 = 1000,       .b.i32 = 2000,        .result.i32 = 3001 },

    /* === SUB (Subtração) === */
    {  7, CV_INT32, cv_type_sub, true,  .a.i32 = 5000000,     .b.i32 = 2000000,     .result.i32 = 3000000 },
    {  8, CV_INT32, cv_type_sub, true,  .a.i32 = -2147483648, .b.i32 = -2147483648, .result.i32 = 0 },
    {  9, CV_INT32, cv_type_sub, true,  .a.i32 = 2147483647,  .b.i32 = -1,          .result.i32 = -2147483648 }, /* Overflow */
    { 10, CV_INT32, cv_type_sub, true,  .a.i32 = -2147483648, .b.i32 = 1,           .result.i32 = 2147483647 },  /* Underflow */
    { 11, CV_INT32, cv_type_sub, false, .a.i32 = 5000,      .b.i32 = 2000,        .result.i32 = 1000 },

    /* === MUL (Multiplicação) === */
    { 12, CV_INT32, cv_type_mul, true,  .a.i32 = 10000,       .b.i32 = 20000,       .result.i32 = 200000000 },
    { 13, CV_INT32, cv_type_mul, true,  .a.i32 = -10000,      .b.i32 = 20000,       .result.i32 = -200000000 },
    { 14, CV_INT32, cv_type_mul, true,  .a.i32 = 2147483647,  .b.i32 = 1,           .result.i32 = 2147483647 },
    { 15, CV_INT32, cv_type_mul, true,  .a.i32 = -2147483648, .b.i32 = 1,           .result.i32 = -2147483648 },
    { 16, CV_INT32, cv_type_mul, true,  .a.i32 = -2147483648, .b.i32 = -1,          .result.i32 = -2147483648 }, /* Overflow de borda */
    { 17, CV_INT32, cv_type_mul, false, .a.i32 = 100,        .b.i32 = 100,         .result.i32 = -10000 },

    /* === DIV (Divisão) === */
    { 18, CV_INT32, cv_type_div, true,  .a.i32 = 200000000,   .b.i32 = 20000,       .result.i32 = 10000 },
    { 19, CV_INT32, cv_type_div, true,  .a.i32 = -200000000,  .b.i32 = 20000,       .result.i32 = -10000 },
    { 20, CV_INT32, cv_type_div, true,  .a.i32 = -2147483648, .b.i32 = 1,           .result.i32 = -2147483648 },

    //{ 21, CV_INT32, cv_type_div, true,  .a.i32 = -2147483648, .b.i32 = -1,          .result.i32 = -2147483648 }, /* INT32_MIN / -1 estoura tipo */
    { 22, CV_INT32, cv_type_div, false, .a.i32 = 10000,      .b.i32 = 10,          .result.i32 = 500 },

    {-1}
};

int runCases(const TestCase cases[], int* total){

    int i, total_failure = 0;

    void* result = malloc(sizeof(double));

    if( result == NULL){
        fprintf(stderr, "Error to alloc result memory.\n");
        return -1;
    }

    for( i = 0; cases[i].index >= 0; i++){    
    
        CVType type = cases[i].type;
        
        bool is_right = cases[i].isEquals;

        const void* a = &cases[i].a;
        const void* b = &cases[i].b;
        
        bool op_ret = cases[i].operation(type, result, a, b);

        if( cv_type_equals(type, result, &cases[i].result) != is_right){

            printf("[ TEST %d:%d ] Test failure.\n", i, cases[i].index);

            total_failure++;
        }
    
    }

    free(result);

    if(total) *total = i;

    return total_failure;
}

int main(int argc, char* argv[]){
    
    int num_cases, num_failures;

    int total_cases = 0, total_fail = 0;

    /* UINT8 */
    printf("\nRunning UINT8 tests:  ");

    num_failures = runCases(cases_u8, &num_cases);

    printf("[%d/%d]\n", num_failures, num_cases);

    total_cases += num_cases;
    total_fail += num_failures;


    /* INT8 */
    printf("\nRunning INT8 tests:   ");

    num_failures = runCases(cases_i8, &num_cases);

    printf("[%d/%d]\n", num_failures, num_cases);

    total_cases += num_cases;
    total_fail += num_failures;

    /* UINT16 */
    printf("\nRunning UINT16 tests: ");

    num_failures = runCases(cases_u16, &num_cases);

    printf("[%d/%d]\n", num_failures, num_cases);

    total_cases += num_cases;
    total_fail += num_failures;

    /* INT16 */
    printf("\nRunning INT16 tests:  ");

    num_failures = runCases(cases_i16, &num_cases);

    printf("[%d/%d]\n", num_failures, num_cases);

    total_cases += num_cases;
    total_fail += num_failures;

    /* UNT32 */
    printf("\nRunning UNT32 tests:  ");

    num_failures = runCases(cases_u32, &num_cases);

    printf("[%d/%d]\n", num_failures, num_cases);

    total_cases += num_cases;
    total_fail += num_failures;

    /* INT32 */
    printf("\nRunning INT32 tests:  ");

    num_failures = runCases(cases_i32, &num_cases);

    printf("[%d/%d]\n", num_failures, num_cases);

    total_cases += num_cases;
    total_fail += num_failures;
    

    /* finnals */
    printf("\n\nTests finish:\n");

    printf("\tTotal of cases:  \t%d\n", total_cases);
    printf("\tTotal of failes:\t%d\n", total_fail);
    printf("\tFailure ratio(%%):\t%.2f%%\n", 100 * (double)total_fail / (double)total_cases);

    return 0;
}