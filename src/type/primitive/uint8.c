
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

    int a_1 = *(const uint8_t*)a;
    int b_1 = *(const uint8_t*)b;
    
    return a_1 - b_1;
}

bool u8_adder(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    *(uint8_t*)dest = *(const uint8_t*)a + *(const uint8_t*)b;

    return true;
}

bool u8_subtractor(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    *(uint8_t*)dest = *(const uint8_t*)a - *(const uint8_t*)b;

    return true;
}

bool u8_multiplier(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    *(uint8_t*)dest = *(const uint8_t*)a * *(const uint8_t*)b;

    return true;
}

bool u8_divider(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    if( *(const uint8_t*)b == 0)
        return false;

    *(uint8_t*)dest = *(const uint8_t*)a / *(const uint8_t*)b;

    return true;
}

bool u8_min(void* value){
    
    if( value == NULL)
        return false;

    *(uint8_t*)value = 0;

    return true;
}

bool u8_max(void* value){
    
    if( value == NULL)
        return false;

    *(uint8_t*)value = UINT8_MAX;

    return true;
}

bool u8_to_string(char* string, const void* value){
    (void*)string;
    (const void*)value;

    // ... not implemented yet

    return false;
}

bool u8_from_string(const char* string, const void* value){
    (const char*) string;
    (const void*)value;

    // ... not implemented yet
    return false;
}
