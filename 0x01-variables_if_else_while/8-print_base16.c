#include <stdio.h>
/**
 * main - prints all the numbers of base 16 in lowercase
 *
 * Return: (0)
 */
int main(void)
{
	int number = 0;

	while (number < 10)
	{
		putchar(number + '0');
			number++;
	}

	number = 'a';

	while (number <= 'f')
	{
		putchar(number);
		number++;
	}
	putchar('\n');
	return (0);
}
