
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

    int a_1 = *(const uint32_t*)a;
    int b_1 = *(const uint32_t*)b;
    
    return a_1 - b_1; // Isso pode dar OF
}

bool u32_adder(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    *(uint32_t*)dest = *(const uint32_t*)a + *(const uint32_t*)b;

    return true;
}

bool u32_subtractor(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    *(uint32_t*)dest = *(const uint32_t*)a - *(const uint32_t*)b;

    return true;
}

bool u32_multiplier(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    *(uint32_t*)dest = *(const uint32_t*)a * *(const uint32_t*)b;

    return true;
}

bool u32_divider(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    if( *(const uint32_t*)b == 0)
        return false;

    *(uint32_t*)dest = *(const uint32_t*)a / *(const uint32_t*)b;

    return true;
}

bool u32_min(void* value){
    
    if( value == NULL)
        return false;

    *(uint32_t*)value = 0;

    return true;
}

bool u32_max(void* value){
    
    if( value == NULL)
        return false;

    *(uint32_t*)value = UINT32_MAX;

    return true;
}

bool u32_to_string(char* string, const void* value){
    (void*)string;
    (const void*)value;

    // ... not implemented yet

    return false;
}

bool u32_from_string(const char* string, const void* value){
    (const char*) string;
    (const void*)value;

    // ... not implemented yet
    return false;
}
