
#include <stdint.h>
#include <limits.h>

#include "int16.h"

bool i16_equals(const void* a, const void* b){
    
    if( a == NULL || b == NULL)
        return false;

    return *(const int16_t*)a == *(const int16_t*)b;
}

int i16_comparer(const void* a, const void* b){
    
    if( a == NULL || b == NULL)
        return INT_MAX;

    int a_1 = *(const int16_t*)a;
    int b_1 = *(const int16_t*)b;
    
    return (a_1 > b_1) - (a_1 < b_1);
}

TypeError i16_adder(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    int32_t result = (int32_t)(*(const int16_t*)a) + *(const int16_t*)b;

    if(result < INT16_MIN)
        return TYPE_ERROR_UNDERFLOW;
        
    if(result > INT16_MAX)
        return TYPE_ERROR_OVERFLOW;

    *(int16_t*)dest = (int16_t)result;

    return TYPE_OK;
}

TypeError i16_subtractor(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    int32_t result = *(const int16_t*)a - *(const int16_t*)b;

    if( result < INT16_MIN)
        return TYPE_ERROR_UNDERFLOW;
    if( result > INT16_MAX)
        return TYPE_ERROR_OVERFLOW;

    *(int16_t*)dest = (int16_t)result;

    return TYPE_OK;
}

TypeError i16_multiplier(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    int32_t result = *(const int16_t*)a * *(const int16_t*)b;
        
    if( result < INT16_MIN)
        return TYPE_ERROR_UNDERFLOW;
    if( result > INT16_MAX)
        return TYPE_ERROR_OVERFLOW;

    *(int16_t*)dest = (int16_t)result;

    return TYPE_OK;
}

TypeError i16_divider(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    int16_t value_a = *(const int16_t*)a;
    int16_t value_b = *(const int16_t*)b;

    if( value_b == 0)
        return TYPE_ERROR_DIVISION_BY_ZERO;

    if (value_a == INT16_MIN && value_b == -1)
        return TYPE_ERROR_OVERFLOW;

    *(int16_t*)dest = value_a / value_b;

    return TYPE_OK;
}

TypeError i16_min(void* value){
    
    if( value == NULL)
        return TYPE_ERROR_NULL_POINTER;

    *(int16_t*)value = INT16_MIN;

    return TYPE_OK;
}

TypeError i16_max(void* value){
    
    if( value == NULL)
        return TYPE_ERROR_NULL_POINTER;

    *(int16_t*)value = INT16_MAX;

    return TYPE_OK;
}

TypeError i16_to_string(char* string, const void* value){
    (void)string;
    (void)value;

    return TYPE_OK;
}

TypeError i16_from_string(void* value, const char* string){
    (void) string;
    (void)value;

    return TYPE_OK;

}
