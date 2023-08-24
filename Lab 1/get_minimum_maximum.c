#include <stdio.h>
#include <math.h>

int get_minimum_and_maximum_digits(int number, int *min, int *max)
{
	number = abs(number);

	while (number > 0)
	{
		int digit = number % 10;

		if (digit < *min)
			*min = digit;
		if (digit > *max)
			*max = digit;

		number /= 10;
	}
}