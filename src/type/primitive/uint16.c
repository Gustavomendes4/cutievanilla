
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

    int a_1 = *(const uint16_t*)a;
    int b_1 = *(const uint16_t*)b;
    
    return a_1 - b_1;
}

bool u16_adder(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    *(uint16_t*)dest = *(const uint16_t*)a + *(const uint16_t*)b;

    return true;
}

bool u16_subtractor(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    *(uint16_t*)dest = *(const uint16_t*)a - *(const uint16_t*)b;

    return true;
}

bool u16_multiplier(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    *(uint16_t*)dest = *(const uint16_t*)a * *(const uint16_t*)b;

    return true;
}

bool u16_divider(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    if( *(const uint16_t*)b == 0)
        return false;

    *(uint16_t*)dest = *(const uint16_t*)a / *(const uint16_t*)b;

    return true;
}

bool u16_min(void* value){
    
    if( value == NULL)
        return false;

    *(uint16_t*)value = 0;

    return true;
}

bool u16_max(void* value){
    
    if( value == NULL)
        return false;

    *(uint16_t*)value = UINT16_MAX;

    return true;
}

bool u16_to_string(char* string, const void* value){
    (void*)string;
    (const void*)value;

    // ... not implemented yet

    return false;
}

bool u16_from_string(const char* string, const void* value){
    (const char*) string;
    (const void*)value;

    // ... not implemented yet
    return false;
}
