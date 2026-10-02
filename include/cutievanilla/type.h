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

bool cv_type_copy(CVType type, void* dest, const void* src);

bool cv_type_set_zero(CVType type, void* dest);

/* Arithmetic */
bool cv_type_add(CVType type, void* dest, const void* a, const void* b);

bool cv_type_sub(CVType type, void* dest, const void* a, const void* b);

bool cv_type_mul(CVType type, void* dest, const void* a, const void* b);

bool cv_type_div(CVType type, void* dest, const void* a, const void* b);

/* Limits */
bool cv_type_min(CVType type, void *dest);

bool cv_type_max(CVType type, void *dest);

/* String */
bool cv_type_to_string(CVType type, char* string, const void* value);

bool cv_type_from_string(CVType type, const char* string, void* value);


#endif //CUTIEVANILLA_METADATA_H_INCLUDED