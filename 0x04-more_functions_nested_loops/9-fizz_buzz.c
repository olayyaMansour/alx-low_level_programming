#include "main.h"
#include <stdio.h>

/**
 * main - prints numbers from 1 to 100, replacing multiples of 3 and 5
 * with "Fizz" and "Buzz" respectively.
 * Return: Always (0)
 */
int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
	if (i % 3 == 0)
	printf("Fizz");
	if (i % 5 == 0)
	printf("Buzz");
	if (i % 3 != 0 && i % 5 != 0)
	printf("%d", i);

	if (i != 100)
	printf(" ");
	}
	printf("\n");
	return (0);
}
