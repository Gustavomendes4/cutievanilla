
#include "float32.h"

bool f32_equals(const void* a, const void* b){
    (const void*)a;
    (const void*)b;
    return false;
}

int f32_comparer(const void* a, const void* b){
    (const void*)a;
    (const void*)b;
    return 0;
}

bool f32_adder(void* dest, const void* a, const void* b){
    
    (const void*)dest;
    (const void*)a;
    (const void*)b;
    return false;
}

bool f32_subtractor(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;
    return false;
}

bool f32_multiplier(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;
    return false;
}

bool f32_divider(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;
    return false;
}

bool f32_min(void* value){
    (void*) value;
    return false;
}

bool f32_max(void* value){
    (void*) value;
    return false;
}

bool f32_to_string(char* string, const void* value){
    (void*) string;
    (const void*) value;
    return false;
}

bool f32_from_string(const char* string, const void* value){
    (void*) string;
    (const void*) value;
    return false;
}
