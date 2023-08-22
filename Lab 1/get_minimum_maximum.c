#include <stdio.h>

int get_minimum_and_maximum_digits(int number, int *min, int *max)
{
	while (number > 0)
	{
		int digit = number % 10;

		if (digit < *min)
			*min = digit;
		if (digit > *max)
			*max = digit;

		number /= 10;
	}

	printf("\nНаименьшая цифра: %d\nНаибольшая цифра: %d\n", *min, *max);
}