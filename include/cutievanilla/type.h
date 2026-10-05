#ifndef CUTIEVANILLA_TYPE_H_INCLUDED
#define CUTIEVANILLA_TYPE_H_INCLUDED

#include <stdbool.h>
#include <stddef.h>

typedef enum {
    TYPE_OK = 0,

    TYPE_ERROR_NULL_POINTER     = 1,
    TYPE_ERROR_INVALID_TYPE     = 2,
    TYPE_INTERNAL_ERROR         = 3,

    TYPE_ERROR_DIVISION_BY_ZERO = 4,
    TYPE_ERROR_OVERFLOW         = 5,
    TYPE_ERROR_UNDERFLOW        = 6,
    TYPE_ERROR_INVALID_VALUE    = 7,
    TYPE_ERROR_INVALID_STRING   = 8

}TypeError;

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

/* Identification */
bool cv_type_is_valid(CVType type);

size_t cv_type_size(CVType type);

const char* cv_type_name(CVType type);

bool cv_type_is_integer(CVType type);

bool cv_type_is_floating(CVType type);

bool cv_type_is_signed(CVType type);


/* Basic operations */
bool cv_type_equals(CVType type, const void* a, const void* b);

int cv_type_compare(CVType type, const void* a, const void* b);

TypeError cv_type_copy(CVType type, void* dest, const void* src);

TypeError cv_type_set_zero(CVType type, void* dest);

/* Arithmetic */
TypeError cv_type_add(CVType type, void* dest, const void* a, const void* b);

TypeError cv_type_sub(CVType type, void* dest, const void* a, const void* b);

TypeError cv_type_mul(CVType type, void* dest, const void* a, const void* b);

TypeError cv_type_div(CVType type, void* dest, const void* a, const void* b);

/* Limits */
TypeError cv_type_min(CVType type, void *dest);

TypeError cv_type_max(CVType type, void *dest);

/* String */
TypeError cv_type_to_string(CVType type, char* string, const void* value);

TypeError cv_type_from_string(CVType type, const char* string, void* value);


#endif //CUTIEVANILLA_METADATA_H_INCLUDED