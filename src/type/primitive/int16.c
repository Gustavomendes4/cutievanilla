
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
    
    return a_1 - b_1;
}

bool i16_adder(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    *(int16_t*)dest = *(const int16_t*)a + *(const int16_t*)b;

    return true;
}

bool i16_subtractor(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    *(int16_t*)dest = *(const int16_t*)a - *(const int16_t*)b;

    return true;
}

bool i16_multiplier(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    *(int16_t*)dest = *(const int16_t*)a * *(const int16_t*)b;

    return true;
}

bool i16_divider(void* dest, const void* a, const void* b){
    
    if( dest == NULL || a == NULL || b == NULL )
        return false;

    if( *(const int16_t*)b == 0)
        return false;

    *(int16_t*)dest = *(const int16_t*)a / *(const int16_t*)b;

    return true;
}

bool i16_min(void* value){
    
    if( value == NULL)
        return false;

    *(int16_t*)value = INT16_MIN;

    return true;
}

bool i16_max(void* value){
    
    if( value == NULL)
        return false;

    *(int16_t*)value = INT16_MAX;

    return true;
}

bool i16_to_string(char* string, const void* value){
    (void*)string;
    (const void*)value;

    return false;
}

bool i16_from_string(const char* string, const void* value){
    (const char*) string;
    (const void*)value;

    return false;

}
