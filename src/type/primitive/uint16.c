
#include <stdint.h>
#include <limits.h>

#include "uint16.h"

bool u16_equals(const void* a, const void* b){
    
    if( a == NULL || b == NULL)
        return false;

    return *(const uint16_t*)a == *(const uint16_t*)b;
}

int u16_comparer(const void* a, const void* b){
    
    if( a == NULL || b == NULL)
        return INT_MAX;

    uint16_t val_a = *(const uint16_t*)a;
    uint16_t val_b = *(const uint16_t*)b;

    return (val_a > val_b) - (val_a < val_b);
}

TypeError u16_adder(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    uint32_t result = (uint32_t)(*(const uint16_t*)a) + *(const uint16_t*)b;
        
    if(result > UINT16_MAX){
        return TYPE_ERROR_OVERFLOW;
    }

    *(uint16_t*)dest = (uint16_t)result;
    
    return TYPE_OK;
}

TypeError u16_subtractor(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    uint16_t val_a = *(const uint16_t*)a;
    uint16_t val_b = *(const uint16_t*)b;

    if( val_a < val_b ){
        return TYPE_ERROR_UNDERFLOW;
    }

    *(uint16_t*)dest = val_a - val_b;

    return TYPE_OK;
}

TypeError u16_multiplier(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    uint32_t result = (uint32_t)(*(const uint16_t*)a) * *(const uint16_t*)b;

    if(result > UINT16_MAX){
        return TYPE_ERROR_OVERFLOW;
    }

    *(uint16_t*)dest = (uint16_t)result;

    return TYPE_OK;
}

TypeError u16_divider(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    if( *(const uint16_t*)b == 0)
        return TYPE_ERROR_DIVISION_BY_ZERO;

    *(uint16_t*)dest = *(const uint16_t*)a / *(const uint16_t*)b;

    return TYPE_OK;
}

TypeError u16_min(void* value){
    
    if( value == NULL)
        return TYPE_ERROR_NULL_POINTER;

    *(uint16_t*)value = 0;

    return TYPE_OK;
}

TypeError u16_max(void* value){
    
    if( value == NULL)
        return TYPE_ERROR_NULL_POINTER;

    *(uint16_t*)value = UINT16_MAX;

    return TYPE_OK;
}

TypeError u16_to_string(char* string, const void* value){

    (void)string;
    (void)value;

    // ... not implemented yet
    return TYPE_OK;
}

TypeError u16_from_string(void* value, const char* string){

    (void)string;
    (void)value;

    // ... not implemented yet
    return TYPE_OK;
}
