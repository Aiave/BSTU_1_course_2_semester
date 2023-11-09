#ifndef ARRAY_H
#define ARRAY_H

struct array
{
    int length;     //длина массива
    int depth;      //глубина массива

    void *values;   //указатель на данные вне зависимости от их типа
};

#endif