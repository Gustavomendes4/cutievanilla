

#include <stdbool.h>

bool u8_equals(const void* a, const void* b);

int u8_comparer(const void* a, const void* b);

bool u8_adder(void* dest, const void* a, const void* b);

bool u8_subtractor(void* dest, const void* a, const void* b);

bool u8_multiplier(void* dest, const void* a, const void* b);

bool u8_divider(void* dest, const void* a, const void* b);

bool u8_min(void* value);

bool u8_max(void* value);

bool u8_to_string(char* string, const void* value);

bool u8_from_string(const char* string, const void* value);