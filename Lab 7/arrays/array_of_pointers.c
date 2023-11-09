#include <stdlib.h>
#include "array_of_pointers.h"

//��������� ������������� ����������� ������� (�������� ������ ����������, ��� ������� ��������� ���������� ������ ��� ������)
//��������� ��������� �� ���������
void array_of_pointers_initialize(struct array *array)
{
    //����������� ��������� values (��������� �� ������ ����������), �������� ������ ���������� (������� �� ����� �������)
    int** values = malloc(array->length * sizeof(int*));
    //����, ���������� ����� ������ �������� ������� ����������, ���������� ������ ��� ������ ������ (������� �� ������� �������)
    for (int i = 0; i < array->length; i++)
        values[i] = (int*)malloc(array->depth * sizeof(int));

    //���� ���������, ����������� ����������, ������������� �������� ��������� �� ������ ����������
    array->values = values; //(*array).values = values;
}

//������������ ������
//��������� ��������� �� ���������, �������������� ����� ������
void array_of_pointers_free(struct array *array)
{
    //������������� ������ ��� ������ ������ �������
    for (int i = 0; i < array->length; i++)
        free(((int**)array->values)[i]);
    //������������� ������ ��� ������� ����������
    free(array->values);

    //����� �������� � ��������� array
    array->length = 0;      //(*array).length = 0;
    array->depth = 0;       //(*array).depth = 0;
    array->values = NULL;   //(*array).values = NULL;
}