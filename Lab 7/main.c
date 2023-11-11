#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include "arrays/array.h"
#include "controller/controller.h"

//Nвар = 1 + 25 % 9 = 8
//8. Определить количество отрицательных чисел в каждой строке.

int main()
{
    setlocale(LC_ALL, "Russian");

    //объявдение переменной array (голубым) типа struct array, где array (бирюзовым) - экземпляр структуры 
    struct array array;

    //приложение работает
    bool is_running = true;

    //operation - экземпляр перечисления enum operation_type, хранит в себе одно из определённых в enum значений
    enum operation_type operation;

    while (is_running)  //пока приложение работает
    {
        //выбор операции
        do {
            printf("Доступные операции\n");
            printf("\t0 - Выход\n");
            printf("\t1 - Обработка одномерного массива\n");
            printf("\t2 - Обработка массива указателей\n");
            printf("Введите тип операции (0-2): ");
            scanf_s("%d", &operation);
        } while (operation < 0 || operation > 2);

        //обработка события "Выход"
        if (operation == terminate)
        {
            is_running = false;
            printf("Пока :3");
            continue;   //выполнение программы переключается на следующую итерацию цикла, происходит выход
        }

        //создание массива, инициализация полей структуры
        do {
            printf("Введите длину массива: ");
            scanf_s("%d", &array.length);
        } while (array.length <= 0);

        do {
            printf("Введите глубину массива: ");
            scanf_s("%d", &array.depth);
        } while (array.depth <= 0);

        //инициализация массива
        initialize_array(operation, &array);

        printf("\n");

        //заполнение массива
        //по строкам массива
        for (int i = 0; i < array.length; i++)
        {
            //по столбцам строки
            for (int j = 0; j < array.depth; j++)
            {
                //инициализация переменной для хранимого значения
                int value = 0;
                //для ввода значений в данном диапазоне (декаративная штука, т.к. у нас 4 символа под число и знак)
                do {
                    printf("Введите значение [%d][%d]: ", i, j);
                    scanf_s("%d", &value);
                } while (value <= -100 || value >= 1000);
                //установка значения в массив по указанным индексам
                set_value(operation, array, i, j, value);
            }
        }
        printf("\n");

        printf("Ваш массив:\n");
        print_array(operation, array);

        printf("Количество отрицательных чисел в каждой строке:\n");
        get_negative_count(operation, array);
    }
	return 0;
}