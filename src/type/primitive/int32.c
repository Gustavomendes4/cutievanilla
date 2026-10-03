
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

    int a_1 = *(const int32_t*)a;
    int b_1 = *(const int32_t*)b;
    
    return a_1 - b_1; // Isso pode gerar OF
}

bool i32_adder(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    *(int32_t*)dest = *(const int32_t*)a + *(const int32_t*)b;

    return true;
}

bool i32_subtractor(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    *(int32_t*)dest = *(const int32_t*)a - *(const int32_t*)b;

    return true;
}

bool i32_multiplier(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    *(int32_t*)dest = *(const int32_t*)a * *(const int32_t*)b;

    return true;
}

bool i32_divider(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    if( *(const int32_t*)b == 0)
        return false;

    *(int32_t*)dest = *(const int32_t*)a / *(const int32_t*)b;

    return true;
}

bool i32_min(void* value){
    
    if( value == NULL)
        return false;

    *(int32_t*)value = INT32_MIN;

    return true;
}

bool i32_max(void* value){
    
    if( value == NULL)
        return false;

    *(int32_t*)value = INT32_MAX;

    return true;
}

bool i32_to_string(char* string, const void* value){
    (void*)string;
    (const void*)value;

    // ... not implemented yet

    return false;
}

bool i32_from_string(const char* string, const void* value){
    (const char*) string;
    (const void*)value;

    // ... not implemented yet
    return false;
}
