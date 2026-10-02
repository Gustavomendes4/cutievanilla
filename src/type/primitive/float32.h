
#include <stdbool.h>

bool f32_equals(const void* a, const void* b);

int f32_comparer(const void* a, const void* b);

bool f32_adder(void* dest, const void* a, const void* b);

bool f32_subtractor(void* dest, const void* a, const void* b);

bool f32_multiplier(void* dest, const void* a, const void* b);

bool f32_divider(void* dest, const void* a, const void* b);

bool f32_min(void* value);

bool f32_max(void* value);

bool f32_to_string(char* string, const void* value);

bool f32_from_string(const char* string, const void* value);
