

#include <stdbool.h>

bool i32_equals(const void* a, const void* b);

int i32_comparer(const void* a, const void* b);

bool i32_adder(void* dest, const void* a, const void* b);

bool i32_subtractor(void* dest, const void* a, const void* b);

bool i32_multiplier(void* dest, const void* a, const void* b);

bool i32_divider(void* dest, const void* a, const void* b);

bool i32_min(void* value);

bool i32_max(void* value);

bool i32_to_string(char* string, const void* value);

bool i32_from_string(const char* string, const void* value);
