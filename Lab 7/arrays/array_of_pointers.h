#ifndef ONE_DIMENSIONAL_ARRAY_H
#define ONE_DIMENSIONAL_ARRAY_H

#include "array.h"

void array_of_pointers_initialize(struct array *array);
void array_of_pointers_free(struct array *array);
void array_of_pointers_set_value(struct array array, int i, int j, int value);
int array_of_pointers_get_value(struct array array, int i, int j);
void array_of_pointers_get_negative_count(struct array array);

#endif