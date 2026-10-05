
#include <stdbool.h>
#include "cutievanilla/type.h"

bool i16_equals(const void* a, const void* b);

int i16_comparer(const void* a, const void* b);

TypeError i16_adder(void* dest, const void* a, const void* b);

TypeError i16_subtractor(void* dest, const void* a, const void* b);

TypeError i16_multiplier(void* dest, const void* a, const void* b);

TypeError i16_divider(void* dest, const void* a, const void* b);

TypeError i16_min(void* value);

TypeError i16_max(void* value);

TypeError i16_to_string(char* string, const void* value);

TypeError i16_from_string(void* value, const char* string);