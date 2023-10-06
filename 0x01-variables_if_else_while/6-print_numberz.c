#include <stdio.h>
/**
 * main - prints all single digit numbers of base 10 starting from 0
 *
 * Return: (0) success
 */
int main(void)
{
	int number = 0;

	while (number < 10)
	{
	putchar(number + '0');
	number++;
	}
	putchar('\n');

	return (0);
}
