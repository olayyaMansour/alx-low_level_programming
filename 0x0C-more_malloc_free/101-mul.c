#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 for success, 98 for error
 */
int main(int argc, char *argv[])
{
	char *num1;
	char *num2;
	int i;
	int j;
	int result;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	num1 = argv[1];
	num2 = argv[2];

	for (i = 0; num1[i] != '\0'; i++)

	for (j = 0; num2[j] != '\0'; j++)

	result = atoi(num1) * atoi(num2);

	printf("%d\n", result);
	return (0);
}

