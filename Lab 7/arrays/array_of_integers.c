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