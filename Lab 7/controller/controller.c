#include <stdio.h>
#include <limits.h>
#include "controller.h"
#include "../arrays/array_of_integers.h"
#include "../arrays/array_of_pointers.h"

//��������� ������������� ������� � ����������� �� ��������� ��������
//��������� � ���� �������� ������������ enum operation_type � ��������� �� ���������, ������� ����� ����������������
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

//������������ �������, ������� ��������, � ����������� �� ��������� ��������
//��������� � ���� �������� ������������ enum operation_type � ��������� �� ���������, ������� �������� ���������� � �������
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