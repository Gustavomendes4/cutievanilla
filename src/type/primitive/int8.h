#include <stdbool.h>

#include "cutievanilla/type.h"

bool i8_equals(const void* a, const void* b);

int i8_comparer(const void* a, const void* b);

TypeError i8_adder(void* dest, const void* a, const void* b);

TypeError i8_subtractor(void* dest, const void* a, const void* b);

TypeError i8_multiplier(void* dest, const void* a, const void* b);

TypeError i8_divider(void* dest, const void* a, const void* b);

TypeError i8_min(void* value);

TypeError i8_max(void* value);

TypeError i8_to_string(char* string, const void* value);

TypeError i8_from_string(void* value, const char* string);