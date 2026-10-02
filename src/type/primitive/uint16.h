

#include <stdbool.h>

bool u16_equals(const void* a, const void* b);

int u16_comparer(const void* a, const void* b);

bool u16_adder(void* dest, const void* a, const void* b);

bool u16_subtractor(void* dest, const void* a, const void* b);

bool u16_multiplier(void* dest, const void* a, const void* b);

bool u16_divider(void* dest, const void* a, const void* b);

bool u16_min(void* value);

bool u16_max(void* value);

bool u16_to_string(char* string, const void* value);

bool u16_from_string(const char* string, const void* value);
