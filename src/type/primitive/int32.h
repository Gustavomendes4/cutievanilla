

#include <stdbool.h>
#include "cutievanilla/type.h"

bool i32_equals(const void* a, const void* b);

int i32_comparer(const void* a, const void* b);

TypeError i32_adder(void* dest, const void* a, const void* b);

TypeError i32_subtractor(void* dest, const void* a, const void* b);

TypeError i32_multiplier(void* dest, const void* a, const void* b);

TypeError i32_divider(void* dest, const void* a, const void* b);

TypeError i32_min(void* value);

TypeError i32_max(void* value);

TypeError i32_to_string(char* string, const void* value);

TypeError i32_from_string(void* value, const char* string);
