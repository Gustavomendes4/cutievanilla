
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#include "cutievanilla.h"
#include "cutievanilla/type.h"

#include "type_internal.h"

#define CV_TYPE_STRING_LENGTH 32

typedef struct _TypeMapping{

    CVType type;

    size_t size;

    const char* string;

    bool is_integer;

    bool is_floating;

    bool is_signed;

    /* functions */
    bool (*equals)(const void* a, const void* b);

    int (*comparer)(const void* a, const void* b);

    TypeError (*adder)(void* dest, const void* a, const void* b);

    TypeError (*subtractor)(void* dest, const void* a, const void* b);

    TypeError (*multiplier)(void* dest, const void* a, const void* b);

    TypeError (*divider)(void* dest, const void* a, const void* b);

    TypeError (*min)(void* value);

    TypeError (*max)(void* value);

    TypeError (*to_string)(char* string, const void* value);

    TypeError (*from_string)(void* value, const char* string);

}TypeMapping;


static const TypeMapping type_mappings[] = {

    // type    |  size | string | is_int | is_float | is_signed | 
    { CV_UINT8,     1,  "uint8"   , true,   false,  false, u8_equals, u8_comparer, u8_adder, u8_subtractor, u8_multiplier, u8_divider, u8_min, u8_max, u8_to_string, u8_from_string },

    { CV_INT8,      1,  "int8"    , true,   false,  true,  i8_equals, i8_comparer, i8_adder, i8_subtractor, i8_multiplier, i8_divider, i8_min, i8_max, i8_to_string, i8_from_string },

    { CV_UINT16,    2,  "uint16"  , true,   false,  false, u16_equals, u16_comparer, u16_adder, u16_subtractor, u16_multiplier, u16_divider, u16_min, u16_max, u16_to_string, u16_from_string },

    { CV_INT16,     2,  "int16"   , true,   false,  true,  i16_equals, i16_comparer, i16_adder, i16_subtractor, i16_multiplier, i16_divider, i16_min, i16_max, i16_to_string, i16_from_string },

    { CV_UINT32,    4,  "uint32"  , true,   false,  false, u32_equals, u32_comparer, u32_adder, u32_subtractor, u32_multiplier, u32_divider, u32_min, u32_max, u32_to_string, u32_from_string },

    { CV_INT32,     4,  "int32"   , true,   false,  true,  i32_equals, i32_comparer, i32_adder, i32_subtractor, i32_multiplier, i32_divider, i32_min, i32_max, i32_to_string, i32_from_string },

    { CV_FLOAT32,   4,  "float32" , false,  true,   true,  f32_equals, f32_comparer, f32_adder, f32_subtractor, f32_multiplier, f32_divider, f32_min, f32_max, f32_to_string, f32_from_string },

    { CV_FLOAT64,   8,  "float64" , false,  true,   true,  f64_equals, f64_comparer, f64_adder, f64_subtractor, f64_multiplier, f64_divider, f64_min, f64_max, f64_to_string, f64_from_string },

    { CV_TYPE_UNKNOWED, 0, "Unknowed"}
};

/* Internal */
static int cv_type_index( CVType type){

    if( type == CV_TYPE_UNKNOWED)
        return -1;

    for( size_t i = 0; type_mappings[i].type != CV_TYPE_UNKNOWED; i++){

        if( type_mappings[i].type == type)
            return i;
    }

    return -2;
}

/* Identification */
bool cv_type_is_valid(CVType type){

    int index = cv_type_index(type);

    if( index < 0) return false;

    return true;
}

size_t cv_type_size(CVType type){

    int index = cv_type_index(type);

    if( index < 0) return 0;

    return type_mappings[index].size;

}

const char* cv_type_name(CVType type){

    int index = cv_type_index(type);

    if( index < 0) return "invalid";

    return type_mappings[index].string;

}

bool cv_type_is_integer(CVType type){

    int index = cv_type_index(type);

    if( index < 0) return false;

    return type_mappings[index].is_integer;
}

bool cv_type_is_floating(CVType type){

    int index = cv_type_index(type);

    if( index < 0) return false;

    return type_mappings[index].is_floating;
}

bool cv_type_is_signed(CVType type){

    int index = cv_type_index(type);

    if( index < 0) return false;

    return type_mappings[index].is_signed;
}


/* Basic operations */
bool cv_type_equals(CVType type, const void* a, const void* b){

    if( a == NULL || b == NULL)
        return false;

    int index = cv_type_index(type);

    if( index < 0) return false;

    if( type_mappings[index].equals == NULL)
        return false;

    return type_mappings[index].equals(a, b);
}

int cv_type_compare(CVType type, const void* a, const void* b){

    if( a == NULL || b == NULL || type == CV_TYPE_UNKNOWED)
        return INT_MIN;

    int index = cv_type_index(type);

    if( index < 0) return INT_MIN;

    return type_mappings[index].comparer(a, b);
}

TypeError cv_type_copy(CVType type, void* dest, const void* src){

    if( dest == NULL || src == NULL)
        return TYPE_ERROR_NULL_POINTER;
        
    size_t size = cv_type_size(type);

    if(size == 0) return TYPE_ERROR_INVALID_TYPE;

    memcpy(dest, src, size);

    return TYPE_OK;
}

TypeError cv_type_set_zero(CVType type, void* dest){

    if(dest == NULL)
        return TYPE_ERROR_NULL_POINTER;

    size_t size = cv_type_size(type);

    if(size == 0) return TYPE_ERROR_INVALID_TYPE;

    memset(dest, 0, size);

    return TYPE_OK;
}

/* Arithmetic */
TypeError cv_type_add(CVType type, void* dest, const void* a, const void* b){

    if( dest == NULL || a == NULL || b == NULL)
        return TYPE_ERROR_NULL_POINTER;

    int index = cv_type_index(type);

    if( index < 0) return TYPE_ERROR_INVALID_TYPE;

    if( type_mappings[index].adder == NULL)
        return TYPE_INTERNAL_ERROR;

    return type_mappings[index].adder(dest, a, b);
}

TypeError cv_type_sub(CVType type, void* dest, const void* a, const void* b){

    if( dest == NULL || a == NULL || b == NULL)
        return TYPE_ERROR_NULL_POINTER;

    int index = cv_type_index(type);

    if( index < 0) return TYPE_ERROR_INVALID_TYPE;

    if( type_mappings[index].subtractor == NULL)
        return TYPE_INTERNAL_ERROR;

    return type_mappings[index].subtractor(dest, a, b);
}

TypeError cv_type_mul(CVType type, void* dest, const void* a, const void* b){

    if( dest == NULL || a == NULL || b == NULL)
        return TYPE_ERROR_NULL_POINTER;

    int index = cv_type_index(type);

    if( index < 0) return TYPE_ERROR_INVALID_TYPE;

    if( type_mappings[index].multiplier == NULL)
        return TYPE_INTERNAL_ERROR;

    return type_mappings[index].multiplier(dest, a, b);
}

TypeError cv_type_div(CVType type, void* dest, const void* a, const void* b){

    if( dest == NULL || a == NULL || b == NULL)
        return TYPE_ERROR_NULL_POINTER;

    int index = cv_type_index(type);

    if( index < 0) return TYPE_ERROR_INVALID_TYPE;

    if( type_mappings[index].divider == NULL)
        return TYPE_INTERNAL_ERROR;

    return type_mappings[index].divider(dest, a, b);
}

/* Limits */
TypeError cv_type_min(CVType type, void *dest){

    if( dest == NULL )
        return TYPE_ERROR_NULL_POINTER;

    int index = cv_type_index(type);

    if( index < 0) return TYPE_ERROR_INVALID_TYPE;

    if( type_mappings[index].min == NULL)
        return TYPE_INTERNAL_ERROR;

    return type_mappings[index].min(dest);
}

TypeError cv_type_max(CVType type, void *dest){

    if( dest == NULL )
        return TYPE_ERROR_NULL_POINTER;

    int index = cv_type_index(type);

    if( index < 0) return TYPE_ERROR_INVALID_TYPE;

    if( type_mappings[index].max == NULL)
        return TYPE_INTERNAL_ERROR;

    return type_mappings[index].max(dest);
}

/* String */
TypeError cv_type_to_string(CVType type, char* string, const void* value){

    if( string == NULL || value == NULL)
        return TYPE_ERROR_NULL_POINTER;

    int index = cv_type_index(type);

    if( index < 0) return TYPE_ERROR_INVALID_TYPE;

    if( type_mappings[index].to_string == NULL)
        return TYPE_INTERNAL_ERROR;

    return type_mappings[index].to_string(string, value);
}

TypeError cv_type_from_string(CVType type, const char* string, void* value){

    if( string == NULL || value == NULL)
        return TYPE_ERROR_NULL_POINTER;

    int index = cv_type_index(type);

    if( index < 0) return TYPE_ERROR_INVALID_TYPE;

    if( type_mappings[index].from_string == NULL)
        return TYPE_INTERNAL_ERROR;

    return type_mappings[index].from_string(value, string);
}
