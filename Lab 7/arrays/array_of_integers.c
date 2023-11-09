#include <stdlib.h>
#include <string.h>
#include "array_of_integers.h"

//�������������� ������ ����������
//��������� ��������� �� ���������
void array_of_integers_initialize(struct array *array)
{
    //�������� ������ ��� ����������� ������� ����� �����
    int *values = malloc(array->length * array->depth * sizeof(int));
    //���� ���������, ����������� ����������, ������������� ����� ���������� ������
    array->values = values; //(*array).values = values;
}

//������������ ������
//��������� ��������� �� ���������, �������������� ����� ������
void array_of_integers_free(struct array *array)
{
    //����������� ������, ���������� ��� ������� ����������
    free(array->values);    //free((*array).values);

    //����� �������� � ��������� array
    array->length = 0;      //(*array).length = 0;
    array->depth = 0;       //(*array).depth = 0;
    array->values = NULL;   //(*array).values = NULL;
}