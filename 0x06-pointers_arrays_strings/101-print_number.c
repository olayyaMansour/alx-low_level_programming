#include "main.h"

/**
 * print_number - Prints an integer using _putchar
 * @num: The integer to print
 */

void print_number(int num)
{
	unsigned int n;

	n = (num < 0) ? -num : num;

	if (num < 0)
		_putchar('-');

	if (n / 10 != 0)
		print_number(n / 10);

	_putchar((n % 10) + '0');
}

