
#include "int32.h"

bool i32_equals(const void* a, const void* b){
    (const void*)a;
    (const void*)b;
    return false;
}

int i32_comparer(const void* a, const void* b){
    (const void*)a;
    (const void*)b;
    return 0;
}

bool i32_adder(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;

    return false;
}

bool i32_subtractor(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;

    return false;
}

bool i32_multiplier(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;

    return false;
}

bool i32_divider(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;

    return false;
}

bool i32_min(void* value){
    (void*) value;

    return false;
}

bool i32_max(void* value){
    (void*) value;

    return false;
}

bool i32_to_string(char* string, const void* value){
    (void*)string;
    (const void*)value;

    return false;
}

bool i32_from_string(const char* string, const void* value){
    (const char*) string;
    (const void*)value;

    return false;

}
