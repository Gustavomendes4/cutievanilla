

#include <stdbool.h>
#include "cutievanilla/type.h"

bool u32_equals(const void* a, const void* b);

int u32_comparer(const void* a, const void* b);

TypeError u32_adder(void* dest, const void* a, const void* b);

TypeError u32_subtractor(void* dest, const void* a, const void* b);

TypeError u32_multiplier(void* dest, const void* a, const void* b);

TypeError u32_divider(void* dest, const void* a, const void* b);

TypeError u32_min(void* value);

TypeError u32_max(void* value);

TypeError u32_to_string(char* string, const void* value);

TypeError u32_from_string(void* value, const char* string);
