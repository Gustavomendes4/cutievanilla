

#include <stdbool.h>

bool i16_equals(const void* a, const void* b);

int i16_comparer(const void* a, const void* b);

bool i16_adder(void* dest, const void* a, const void* b);

bool i16_subtractor(void* dest, const void* a, const void* b);

bool i16_multiplier(void* dest, const void* a, const void* b);

bool i16_divider(void* dest, const void* a, const void* b);

bool i16_min(void* value);

bool i16_max(void* value);

bool i16_to_string(char* string, const void* value);

bool i16_from_string(const char* string, const void* value);