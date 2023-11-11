#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_of_integers.h"

//инициализирует массив указателей
//принимает указатель на структуру
void array_of_integers_initialize(struct array *array)
{
    //выделяем память для одномерного массива целых чисел
    int *values = malloc(array->length * array->depth * sizeof(int));
    //полю структуры, являющемуся указателем, присваивается адрес выделенной памяти
    array->values = values; //(*array).values = values;
}

//высвобождает память
//принимает указатель на структуру, представляющую собой массив
void array_of_integers_free(struct array *array)
{
    //освобождает память, выделенную для массива указателей
    free(array->values);    //free((*array).values);

    //сброс значений в структуре array
    array->length = 0;      //(*array).length = 0;
    array->depth = 0;       //(*array).depth = 0;
    array->values = NULL;   //(*array).values = NULL;
}

//устанавливает значения в массиве
//принимает в себя двумерный массив, его индексы i и j, значение для установки
void array_of_integers_set_value(struct array array, int i, int j, int value)
{
    //преобразование указателя array.values к типу int*, чтобы получить доступ к элементу массива
    ((int*)array.values)[i * array.depth + j] = value;
    //i* array.depth    -   смещение на i - ю строку.
    //+ j               -   добавление смещения на j - й столбец внутри строки.
}

//возвращает значения из массива, представленного в виде одномерного массива
//принимает в себя двумерный массив, его индексы i и j
//возвращает значение из массива
int array_of_integers_get_value(struct array array, int i, int j)
{
    return ((int*)array.values)[i * array.depth + j];
}

//считает количество отрицательных элементов в каждой строке и выводит на экран
//принимает в себя двумерный массив
void array_of_integers_get_negative_count(struct array array)
{
    for (int i = 0; i < array.length; i++)
    {
        int negative_count = 0;
        for (int j = 0; j < array.depth; j++)
        {
            if (((int*)array.values)[i * array.depth + j] < 0)
                negative_count++;
        }
        printf("Строка %d: %d.\n", i + 1, negative_count);
    }
}