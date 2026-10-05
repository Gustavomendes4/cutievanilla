
#include <stdint.h>
#include <limits.h>

#include "uint8.h"

bool u8_equals(const void* a, const void* b){
    
    if( a == NULL || b == NULL)
        return false;

    return *(const uint8_t*)a == *(const uint8_t*)b;
}

int u8_comparer(const void* a, const void* b){
    
    if( a == NULL || b == NULL)
        return INT_MAX;

    uint8_t val_a = *(const uint8_t*)a;
    uint8_t val_b = *(const uint8_t*)b;

    return (val_a > val_b) - (val_a < val_b);
}

TypeError u8_adder(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    uint16_t result = (uint16_t)(*(const uint8_t*)a) + *(const uint8_t*)b;

    if( result > UINT8_MAX){
        return TYPE_ERROR_OVERFLOW;
    }

    *(uint8_t*)dest = (uint8_t)result;

    return TYPE_OK;
}

TypeError u8_subtractor(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    uint8_t val_a = *(const uint8_t*)a;
    uint8_t val_b = *(const uint8_t*)b;

    if( val_a < val_b){
        return TYPE_ERROR_UNDERFLOW;
    }

    *(uint8_t*)dest = val_a - val_b;

    return TYPE_OK;
}

TypeError u8_multiplier(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    uint16_t result = (uint16_t)(*(const uint8_t*)a) * *(const uint8_t*)b;

    if(result > UINT8_MAX){
        return TYPE_ERROR_OVERFLOW;
    }

    *(uint8_t*)dest = (uint8_t)result;

    return TYPE_OK;
}

TypeError u8_divider(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    if( *(const uint8_t*)b == 0)
        return TYPE_ERROR_DIVISION_BY_ZERO;

    *(uint8_t*)dest = *(const uint8_t*)a / *(const uint8_t*)b;

    return TYPE_OK;
}

TypeError u8_min(void* value){
    
    if( value == NULL)
        return TYPE_ERROR_NULL_POINTER;

    *(uint8_t*)value = 0;

    return TYPE_OK;
}

TypeError u8_max(void* value){
    
    if( value == NULL)
        return TYPE_ERROR_NULL_POINTER;

    *(uint8_t*)value = UINT8_MAX;

    return TYPE_OK;
}

TypeError u8_to_string(char* string, const void* value){
    
    (void)string;
    (void)value;

    // ... not implemented yet

    return TYPE_OK;
}

TypeError u8_from_string(void* value, const char* string){

    (void)string;
    (void)value;

    // ... not implemented yet
    return TYPE_OK;
}
