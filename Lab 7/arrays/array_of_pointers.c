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