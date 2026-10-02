
#include "uint16.h"

bool u16_equals(const void* a, const void* b){
    (const void*)a;
    (const void*)b;
    return false;
}

int u16_comparer(const void* a, const void* b){
    (const void*)a;
    (const void*)b;
    return 0;
}

bool u16_adder(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;

    return false;
}

bool u16_subtractor(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;

    return false;
}

bool u16_multiplier(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;

    return false;
}

bool u16_divider(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;

    return false;
}

bool u16_min(void* value){
    (void*) value;

    return false;
}

bool u16_max(void* value){
    (void*) value;

    return false;
}

bool u16_to_string(char* string, const void* value){
    (void*)string;
    (const void*)value;

    return false;
}

bool u16_from_string(const char* string, const void* value){
    (const char*) string;
    (const void*)value;

    return false;

}
