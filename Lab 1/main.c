#include <stdio.h>
#include <locale.h>
#include "get_minimum_maximum.h"

//Nвар = 25 % 10 + 1 = 6
//6. Найти наибольшую и наименьшую цифры в записи числа.

int main()
{
	setlocale(LC_ALL, "Russian");
	
	int number;
	printf("Введите целое число, наименьшую и наибольшую цифры которого хотите найти:\n");
	scanf_s("%d", &number);

	int maximum_digit = 0, minimum_digit = 9;
	get_minimum_and_maximum_digits(number, &minimum_digit, &maximum_digit);

	printf("\nНаименьшая цифра: %d\nНаибольшая цифра: %d\n", minimum_digit, maximum_digit);

	return 0;
}