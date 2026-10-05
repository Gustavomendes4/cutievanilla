
#include <stdint.h>
#include <limits.h>

#include "uint32.h"

bool u32_equals(const void* a, const void* b){
    
    if( a == NULL || b == NULL)
        return false;

    return *(const uint32_t*)a == *(const uint32_t*)b;
}

int u32_comparer(const void* a, const void* b){
    
    if( a == NULL || b == NULL)
        return INT_MAX;

    uint32_t val_a = *(const uint32_t*)a;
    uint32_t val_b = *(const uint32_t*)b;
    
    // return a_1 - b_1; // Isso pode dar OF
    return (val_a > val_b) - (val_a < val_b); // Retorna 1, -1 ou 0 de forma 100% segura
}

TypeError u32_adder(void* dest, const void* a, const void* b){

    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    uint64_t result = (uint64_t)(*(const uint32_t*)a) + *(const uint32_t*)b;

    if(result > UINT32_MAX){
        return TYPE_ERROR_OVERFLOW;
    }

    *(uint32_t*)dest = (uint32_t)result;

    return TYPE_OK;
}

TypeError u32_subtractor(void* dest, const void* a, const void* b){

    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    uint32_t val_a = *(const uint32_t*)a;
    uint32_t val_b = *(const uint32_t*)b;
    
    if( val_a < val_b){
        return TYPE_ERROR_UNDERFLOW;
    }
    
    *(uint32_t*)dest = val_a - val_b;

    return TYPE_OK;
}

TypeError u32_multiplier(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    uint64_t result = (uint64_t)(*(const uint32_t*)a) * *(const uint32_t*)b;

    if(result > UINT32_MAX){
        return TYPE_ERROR_OVERFLOW;
    }

    *(uint32_t*)dest = (uint32_t)result;

    return TYPE_OK;
}

TypeError u32_divider(void* dest, const void* a, const void* b){

    if( dest == NULL || a == NULL || b == NULL )
        return TYPE_ERROR_NULL_POINTER;

    if( *(const uint32_t*)b == 0)
        return TYPE_ERROR_DIVISION_BY_ZERO;

    *(uint32_t*)dest = *(const uint32_t*)a / *(const uint32_t*)b;

    return TYPE_OK;
}

TypeError u32_min(void* value){
    
    if( value == NULL)
        return TYPE_ERROR_NULL_POINTER;

    *(uint32_t*)value = 0;

    return TYPE_OK;
}

TypeError u32_max(void* value){
    
    if( value == NULL)
        return TYPE_ERROR_NULL_POINTER;

    *(uint32_t*)value = UINT32_MAX;

    return TYPE_OK;
}

TypeError u32_to_string(char* string, const void* value){
    (void)string;
    (void)value;

    // ... not implemented yet

    return TYPE_OK;
}

TypeError u32_from_string(void* value, const char* string){
    (void) string;
    (void)value;

    // ... not implemented yet
    return TYPE_OK;
}
