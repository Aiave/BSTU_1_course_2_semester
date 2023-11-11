#ifndef ARRAY_OF_POINTERS_H
#define ARRAY_OF_POINTERS_H

#include "array.h"

void array_of_integers_initialize(struct array *array);
void array_of_integers_free(struct array *array);
void array_of_integers_set_value(struct array array, int i, int j, int value);
int array_of_integers_get_value(struct array array, int i, int j);
void array_of_integers_get_negative_count(struct array array);

#endif