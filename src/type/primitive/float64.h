

#include <stdbool.h>

bool f64_equals(const void* a, const void* b);

int f64_comparer(const void* a, const void* b);

bool f64_adder(void* dest, const void* a, const void* b);

bool f64_subtractor(void* dest, const void* a, const void* b);

bool f64_multiplier(void* dest, const void* a, const void* b);

bool f64_divider(void* dest, const void* a, const void* b);

bool f64_min(void* value);

bool f64_max(void* value);

bool f64_to_string(char* string, const void* value);

bool f64_from_string(const char* string, const void* value);