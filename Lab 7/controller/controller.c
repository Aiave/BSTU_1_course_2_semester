#include <stdio.h>
#include <limits.h>
#include "controller.h"
#include "../arrays/array_of_integers.h"
#include "../arrays/array_of_pointers.h"

//выполняет инициализацию массива в зависимости от выбранной операции
//принимает в себя значение перечисления enum operation_type и указатель на структуру, которую нужно инициализировать
void initialize_array(enum operation_type operation, struct array *array)
{
    switch (operation)
    {
    case process_array_of_integers:
        array_of_integers_initialize(array);
        break;
    case process_array_of_pointers:
        array_of_pointers_initialize(array);
        break;
    }
}

//высвобождает ресурсы, занятые массивом, в зависимости от выбранной операции
//принимает в себя значение перечисления enum operation_type и указатель на структуру, которая содержит информацию о массиве
void free_array(enum operation_type operation, struct array *array)
{
    switch (operation)
    {
    case process_array_of_integers:
        array_of_integers_free(array);
        break;
    case process_array_of_pointers:
        array_of_pointers_free(array);
        break;
    }
}

//устанавливает значения в массиве в зависимости от типа операции
//принимает в себя значение перечисления enum operation_type, двумерный массив, его индексы i и j, значение для установки
void set_value(enum operation_type operation, struct array array, int i, int j, int value)
{
    switch (operation)
    {
    case process_array_of_integers:
        array_of_integers_set_value(array, i, j, value);
        break;
    case process_array_of_pointers:
        array_of_pointers_set_value(array, i, j, value);
        break;
    }
}

//получает значения массива в зависимости от выбранной операции
//принимает в себя значение перечисления enum operation_type, двумерный массив, его индексы i и j
int get_value(enum operation_type operation, struct array array, int i, int j)
{
    switch (operation)
    {
    case process_array_of_integers:
        return array_of_integers_get_value(array, i, j);
    case process_array_of_pointers:
        return array_of_pointers_get_value(array, i, j);
    }
    return 0;
}

//получает и выводит количество отрицательных элементов в каждой строке
//принимает в себя значение перечисления enum operation_type, двумерный массив, его индексы i и j
void get_negative_count(enum operation_type operation, struct array array)
{
    switch (operation)
    {
    case process_array_of_integers:
        array_of_integers_get_negative_count(array);
    case process_array_of_pointers:
        array_of_pointers_get_negative_count(array);
    }
    return 0;
}

//выводит массив
//принимает в себя значение перечисления enum operation_type и двумерный массив
void print_array(enum operation_type operation, struct array array)
{
    //по строкам
    for (int i = 0; i < array.length; i++)
    {
        printf("\t");   //отступ перед строкой
        //по столбцам
        for (int j = 0; j < array.depth; j++)
        {
            //вывод значения, используя функцию для его получения
            printf("%4d", get_value(operation, array, i, j));
        }
        printf("\n");   //переход на новую строку после вывода строки
    }
    printf("\n");       //переход на новую строку после вывода массива
}
