#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../arrays/array.h"

enum operation_type
{
    terminate,                  //����������
    process_array_of_integers,  //��������� ����������� �������
    process_array_of_pointers   //��������� ������� ����������
};

void initialize_array(enum operation_type operation, struct array *array);
void free_array(enum operation_type operation, struct array *array);

#endif