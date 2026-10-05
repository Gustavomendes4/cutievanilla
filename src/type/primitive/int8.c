
#include <stdint.h>
#include <limits.h>

#include "int8.h"

bool i8_equals(const void* a, const void* b){
    
    if( a == NULL || b == NULL)
        return false;

    return *(const int8_t*)a == *(const int8_t*)b;
}

int i8_comparer(const void* a, const void* b){
    
    if( a == NULL || b == NULL)
        return INT_MAX;

    int a_1 = *(const int8_t*)a;
    int b_1 = *(const int8_t*)b;
    
    return (a_1 > b_1) - (a_1 < b_1);
}

TypeError i8_adder(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    int16_t result = *(const int8_t*)a + *(const int8_t*)b;

    if( result > INT8_MAX){
        return TYPE_ERROR_OVERFLOW;
    }

    if( result < INT8_MIN){
        return TYPE_ERROR_UNDERFLOW;
    }

    *(int8_t*)dest = (int8_t)result;

    return TYPE_OK;
}

TypeError i8_subtractor(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    int16_t result = *(const int8_t*)a - *(const int8_t*)b;

    if( result < INT8_MIN)
        return TYPE_ERROR_UNDERFLOW;
    if( result > INT8_MAX)
        return TYPE_ERROR_OVERFLOW;

    *(int8_t*)dest = (int8_t)result;

    return TYPE_OK;
}

TypeError i8_multiplier(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    int16_t result = *(const int8_t*)a * *(const int8_t*)b;
        
    if( result < INT8_MIN)
        return TYPE_ERROR_UNDERFLOW;
    if( result > INT8_MAX)
        return TYPE_ERROR_OVERFLOW;

    *(int8_t*)dest = (int8_t)result;

    return TYPE_OK;
}

TypeError i8_divider(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    int8_t value_a = *(const int8_t*)a;
    int8_t value_b = *(const int8_t*)b;

    if( value_b == 0)
        return TYPE_ERROR_DIVISION_BY_ZERO;

    if (value_a == INT8_MIN && value_b == -1)
        return TYPE_ERROR_OVERFLOW;

    *(int8_t*)dest = value_a / value_b;

    return TYPE_OK;
}

TypeError i8_min(void* value){
    
    if( value == NULL)
        return TYPE_ERROR_NULL_POINTER;

    *(int8_t*)value = INT8_MIN;

    return TYPE_OK;
}

TypeError i8_max(void* value){
    
    if( value == NULL)
        return TYPE_ERROR_NULL_POINTER;

    *(int8_t*)value = INT8_MAX;

    return TYPE_OK;
}

TypeError i8_to_string(char* string, const void* value){

    (void)string;
    (void)value;

    // ... not implemented yet
    return TYPE_OK;
}

TypeError i8_from_string(void* value, const char* string){

    (void)string;
    (void)value;

    // ... not implemented yet
    return TYPE_OK;
}