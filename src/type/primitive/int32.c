
#include <stdint.h>
#include <limits.h>

#include "int32.h"

bool i32_equals(const void* a, const void* b){
    
    if( a == NULL || b == NULL)
        return false;

    return *(const int32_t*)a == *(const int32_t*)b;
}

int i32_comparer(const void* a, const void* b){
    
    if( a == NULL || b == NULL)
        return INT_MAX;

    int32_t a_1 = *(const int32_t*)a;
    int32_t b_1 = *(const int32_t*)b;
    
    return (a_1 > b_1) - (a_1 < b_1);
}

TypeError i32_adder(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    int64_t result = ((int64_t)*(const int32_t*)a) + *(const int32_t*)b;

    if(result < INT32_MIN)
        return TYPE_ERROR_UNDERFLOW;
        
    if(result > INT32_MAX)
        return TYPE_ERROR_OVERFLOW;
    
    *(int32_t*)dest = (int32_t)result;
    
    return TYPE_OK;
}

TypeError i32_subtractor(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    int64_t result = (int64_t)(*(const int32_t*)a) - *(const int32_t*)b;

    if( result < INT32_MIN)
        return TYPE_ERROR_UNDERFLOW;
    if( result > INT32_MAX)
        return TYPE_ERROR_OVERFLOW;

    *(int32_t*)dest = (int32_t)result;

    return TYPE_OK;
}

TypeError i32_multiplier(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    int64_t result = (int64_t)(*(const int32_t*)a) * *(const int32_t*)b;
        
    if( result < INT32_MIN)
        return TYPE_ERROR_UNDERFLOW;
    if( result > INT32_MAX)
        return TYPE_ERROR_OVERFLOW;

    *(int32_t*)dest = (int32_t)result;

    return TYPE_OK;
}

TypeError i32_divider(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    int32_t value_a = *(const int32_t*)a;
    int32_t value_b = *(const int32_t*)b;

    if( value_b == 0)
        return TYPE_ERROR_DIVISION_BY_ZERO;

    if (value_a == INT32_MIN && value_b == -1)
        return TYPE_ERROR_OVERFLOW;

    *(int32_t*)dest = value_a / value_b;

    return TYPE_OK;
}

TypeError i32_min(void* value){
    
    if( value == NULL)
        return TYPE_ERROR_NULL_POINTER;

    *(int32_t*)value = INT32_MIN;

    return TYPE_OK;
}

TypeError i32_max(void* value){
    
    if( value == NULL)
        return TYPE_ERROR_NULL_POINTER;

    *(int32_t*)value = INT32_MAX;

    return TYPE_OK;
}

TypeError i32_to_string(char* string, const void* value){
    (void)string;
    (void)value;

    // ... not implemented yet

    return TYPE_OK;
}

TypeError i32_from_string(void* value, const char* string){
    (void) string;
    (void)value;

    // ... not implemented yet
    return TYPE_OK;
}
