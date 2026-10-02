
#include "uint32.h"

bool u32_equals(const void* a, const void* b){
    (const void*)a;
    (const void*)b;
    return false;
}

int u32_comparer(const void* a, const void* b){
    (const void*)a;
    (const void*)b;
    return 0;
}

bool u32_adder(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;

    return false;
}

bool u32_subtractor(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;

    return false;
}

bool u32_multiplier(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;

    return false;
}

bool u32_divider(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;

    return false;
}

bool u32_min(void* value){
    (void*) value;

    return false;
}

bool u32_max(void* value){
    (void*) value;

    return false;
}

bool u32_to_string(char* string, const void* value){
    (void*)string;
    (const void*)value;

    return false;
}

bool u32_from_string(const char* string, const void* value){
    (const char*) string;
    (const void*)value;

    return false;

}
