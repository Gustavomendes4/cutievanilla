#ifndef CUTIEVANILLA_TYPE_H_INCLUDED
#define CUTIEVANILLA_TYPE_H_INCLUDED

#include <stdbool.h>

typedef enum _CVType{
    CV_UINT8 = 0,
    CV_INT8,
    CV_UINT16,
    CV_INT16,
    CV_UINT32,
    CV_INT32,
    CV_FLOAT32,
    CV_FLOAT64,

    CV_TYPE_UNKNOWED

}CVType;

size_t cv_type_size(CVType type);

bool cv_type_to_string(char* buffer, const void* value, CVType type);

bool cv_type_is_equals(CVType type, const void* a, const void* b);

#endif //CUTIEVANILLA_METADATA_H_INCLUDED