#include <stdio.h>
#include <stdlib.h>
#include "array_of_pointers.h"

//выполняет инициализацию одномерного массива (создаётся массив указателей, для каждого указателя выделяется память под строку)
//принимает указатель на структуру
void array_of_pointers_initialize(struct array *array)
{
    //объявляется указатель values (указывает на массив указателей), создаётся массив указателей (зависит от длины массива)
    int** values = malloc(array->length * sizeof(int*));
    //цикл, проходящий через каждый эллемент массива указателей, выделяется память для каждой строки (зависит от глубины массива)
    for (int i = 0; i < array->length; i++)
        values[i] = (int*)malloc(array->depth * sizeof(int));

    //полю структуры, являющемуся указателем, присваивается значение указателя на массив указателей
    array->values = values; //(*array).values = values;
}

//высвобождает память
//принимает указатель на структуру, представляющую собой массив
void array_of_pointers_free(struct array *array)
{
    //высвобождение памяти для каждой строки массива
    for (int i = 0; i < array->length; i++)
        free(((int**)array->values)[i]);
    //высвобождение памяти для массива указателей
    free(array->values);

    //сброс значений в структуре array
    array->length = 0;      //(*array).length = 0;
    array->depth = 0;       //(*array).depth = 0;
    array->values = NULL;   //(*array).values = NULL;
}

//устанавливает значения в массиве
//принимает в себя двумерный массив, его индексы i и j, значение для установки
void array_of_pointers_set_value(struct array array, int i, int j, int value)
{
    //преобразование указателя array.values к типу int**, чтобы получить доступ к элементу массива
    ((int**)array.values)[i][j] = value;
}

//возвращает значения из массива, представленного массивом указателей
//принимает в себя двумерный массив, его индексы i и j
//возвращает значение из массива
int array_of_pointers_get_value(struct array array, int i, int j)
{
    return ((int**)array.values)[i][j];
}

//считает количество отрицательных элементов в каждой строке и выводит на экран
//принимает в себя двумерный массив
void array_of_pointers_get_negative_count(struct array array)
{
    for (int i = 0; i < array.length; i++)
    {
        int negative_count = 0;
        for (int j = 0; j < array.depth; j++)
        {
            if (((int**)array.values)[i][j] < 0)
                negative_count++;
        }
        printf("Строка %d: %d.\n", i + 1, negative_count);
    }
}