

#include <stdbool.h>

bool u32_equals(const void* a, const void* b);

int u32_comparer(const void* a, const void* b);

bool u32_adder(void* dest, const void* a, const void* b);

bool u32_subtractor(void* dest, const void* a, const void* b);

bool u32_multiplier(void* dest, const void* a, const void* b);

bool u32_divider(void* dest, const void* a, const void* b);

bool u32_min(void* value);

bool u32_max(void* value);

bool u32_to_string(char* string, const void* value);

bool u32_from_string(const char* string, const void* value);
