#ifndef CUTIEVANILLA_H_INCLUDED
#define CUTIEVANILLA_H_INCLUDED


#define SZ_LIST(...) (size_t[]){__VA_ARGS__}

#define U8_LIST(...) (uint8_t[]){__VA_ARGS__}
#define I8_LIST(...) (int8_t[]){__VA_ARGS__}

#define U16_LIST(...) (uint16_t[]){__VA_ARGS__}
#define I16_LIST(...) (int16_t[]){__VA_ARGS__}

#define U32_LIST(...) (int16_t[]){__VA_ARGS__}
#define I32_LIST(...) (int16_t[]){__VA_ARGS__}


#include "cutievanilla/type.h"

#include "cutievanilla/region.h"

#include "cutievanilla/metadata.h"

#include "cutievanilla/matrix.h"

#include "cutievanilla/histogram.h"


#include "cutievanilla/image.h"

#endif // CUTIEVANILLA_H_INCLUDED