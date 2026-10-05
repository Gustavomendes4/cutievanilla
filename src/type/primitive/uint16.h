

#include <stdbool.h>
#include "cutievanilla/type.h"

bool u16_equals(const void* a, const void* b);

int u16_comparer(const void* a, const void* b);

TypeError u16_adder(void* dest, const void* a, const void* b);

TypeError u16_subtractor(void* dest, const void* a, const void* b);

TypeError u16_multiplier(void* dest, const void* a, const void* b);

TypeError u16_divider(void* dest, const void* a, const void* b);

TypeError u16_min(void* value);

TypeError u16_max(void* value);

TypeError u16_to_string(char* string, const void* value);

TypeError u16_from_string(void* value, const char* string);
