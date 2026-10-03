
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
    
    return a_1 - b_1;
}

bool i8_adder(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    *(int8_t*)dest = *(const int8_t*)a + *(const int8_t*)b;

    return true;
}

bool i8_subtractor(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    *(int8_t*)dest = *(const int8_t*)a - *(const int8_t*)b;

    return true;
}

bool i8_multiplier(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    *(int8_t*)dest = *(const int8_t*)a * *(const int8_t*)b;

    return true;
}

bool i8_divider(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    if( *(const int8_t*)b == 0)
        return false;

    *(int8_t*)dest = *(const int8_t*)a / *(const int8_t*)b;

    return true;
}

bool i8_min(void* value){
    
    if( value == NULL)
        return false;

    *(int8_t*)value = INT8_MIN;

    return true;
}

bool i8_max(void* value){
    
    if( value == NULL)
        return false;

    *(int8_t*)value = INT8_MAX;

    return true;
}

bool i8_to_string(char* string, const void* value){
    (void*)string;
    (const void*)value;

    // ... not implemented yet

    return false;
}

bool i8_from_string(const char* string, const void* value){
    (const char*) string;
    (const void*)value;

    // ... not implemented yet
    return false;
}
