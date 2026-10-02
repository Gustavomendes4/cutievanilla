

#include <stdbool.h>

bool i8_equals(const void* a, const void* b);

int i8_comparer(const void* a, const void* b);

bool i8_adder(void* dest, const void* a, const void* b);

bool i8_subtractor(void* dest, const void* a, const void* b);

bool i8_multiplier(void* dest, const void* a, const void* b);

bool i8_divider(void* dest, const void* a, const void* b);

bool i8_min(void* value);

bool i8_max(void* value);

bool i8_to_string(char* string, const void* value);

bool i8_from_string(const char* string, const void* value);