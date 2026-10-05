
#include <stdbool.h>
#include "cutievanilla/type.h"

bool f32_equals(const void* a, const void* b);

int f32_comparer(const void* a, const void* b);

TypeError f32_adder(void* dest, const void* a, const void* b);

TypeError f32_subtractor(void* dest, const void* a, const void* b);

TypeError f32_multiplier(void* dest, const void* a, const void* b);

TypeError f32_divider(void* dest, const void* a, const void* b);

TypeError f32_min(void* value);

TypeError f32_max(void* value);

TypeError f32_to_string(char* string, const void* value);

TypeError f32_from_string(void* value, const char* string);
