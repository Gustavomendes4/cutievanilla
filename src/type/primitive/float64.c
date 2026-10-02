
#include "float64.h"

bool f64_equals(const void* a, const void* b){
    (const void*)a;
    (const void*)b;
    return false;
}

int f32_comparer(const void* a, const void* b){
    (const void*)a;
    (const void*)b;
    return 0;
}

bool f64_adder(void* dest, const void* a, const void* b){
    
    (const void*)dest;
    (const void*)a;
    (const void*)b;
    return false;
}

bool f64_subtractor(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;
    return false;
}

bool f64_multiplier(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;
    return false;
}

bool f64_divider(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;
    return false;
}

bool f64_min(void* value){
    (void*) value;
    return false;
}

bool f64_max(void* value){
    (void*) value;
    return false;
}

bool f64_to_string(char* string, const void* value){
    (void*) string;
    (const void*) value;
    return false;
}

bool f64_from_string(const char* string, const void* value){
    (void*) string;
    (const void*) value;
    return false;
}
