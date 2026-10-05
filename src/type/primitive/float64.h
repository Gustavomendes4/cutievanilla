

#include <stdbool.h>
#include "cutievanilla/type.h"

bool f64_equals(const void* a, const void* b);

int f64_comparer(const void* a, const void* b);

TypeError f64_adder(void* dest, const void* a, const void* b);

TypeError f64_subtractor(void* dest, const void* a, const void* b);

TypeError f64_multiplier(void* dest, const void* a, const void* b);

TypeError f64_divider(void* dest, const void* a, const void* b);

TypeError f64_min(void* value);

TypeError f64_max(void* value);

TypeError f64_to_string(char* string, const void* value);

TypeError f64_from_string(void* value, const char* string);