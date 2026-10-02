
#include "uint8.h"

bool i8_equals(const void* a, const void* b){
    (const void*)a;
    (const void*)b;
    return false;
}

int i8_comparer(const void* a, const void* b){
    (const void*)a;
    (const void*)b;
    return 0;
}

bool i8_adder(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;

    return false;
}

bool i8_subtractor(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;

    return false;
}

bool i8_multiplier(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;

    return false;
}

bool i8_divider(void* dest, const void* a, const void* b){
    (void*) dest;
    (const void*) a;
    (const void*) b;

    return false;
}

bool i8_min(void* value){
    (void*) value;

    return false;
}

bool i8_max(void* value){
    (void*) value;

    return false;
}

bool i8_to_string(char* string, const void* value){
    (void*)string;
    (const void*)value;

    return false;
}

bool i8_from_string(const char* string, const void* value){
    (const char*) string;
    (const void*)value;

    return false;

}
