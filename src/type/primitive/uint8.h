
#include <stdbool.h>

#include "cutievanilla/type.h"

bool u8_equals(const void* a, const void* b);

int u8_comparer(const void* a, const void* b);

TypeError u8_adder(void* dest, const void* a, const void* b);

TypeError u8_subtractor(void* dest, const void* a, const void* b);

TypeError u8_multiplier(void* dest, const void* a, const void* b);

TypeError u8_divider(void* dest, const void* a, const void* b);

TypeError u8_min(void* value);

TypeError u8_max(void* value);

TypeError u8_to_string(char* string, const void* value);

TypeError u8_from_string(void* value, const char* string);