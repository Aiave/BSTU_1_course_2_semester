﻿#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../arrays/array.h"

enum operation_type
{
    terminate,                  //завершение
    process_array_of_integers,  //обработка одномерного массива
    process_array_of_pointers   //обработка массива указателей
};

void initialize_array(enum operation_type operation, struct array *array);
void free_array(enum operation_type operation, struct array *array);
void set_value(enum operation_type operation, struct array array, int i, int j, int value);
int get_value(enum operation_type operation, struct array array, int i, int j);
void get_negative_count(enum operation_type operation, struct array array);
void print_array(enum operation_type operation, struct array array);

#endif