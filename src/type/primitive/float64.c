
#include "float64.h"

bool f64_equals(const void* a, const void* b){
    (const void*)a;
    (const void*)b;
    return false;
}

int f64_comparer(const void* a, const void* b){
    (const void*)a;
    (const void*)b;
    return 0;
}

TypeError f64_adder(void* dest, const void* a, const void* b){
    
    (const void*)dest;
    (const void*)a;
    (const void*)b;
    return false;
}

TypeError f64_subtractor(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;
    return false;
}

TypeError f64_multiplier(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;
    return false;
}

TypeError f64_divider(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;
    return false;
}

TypeError f64_min(void* value){
    (void*) value;
    return false;
}

TypeError f64_max(void* value){
    (void*) value;
    return false;
}

TypeError f64_to_string(char* string, const void* value){
    (void*) string;
    (const void*) value;
    return false;
}

TypeError f64_from_string(void* value, const char* string){
    (void*) string;
    (const void*) value;
    return false;
}
