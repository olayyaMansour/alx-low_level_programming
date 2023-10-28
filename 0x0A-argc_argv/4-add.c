#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/**
 * main - Entry point of the program
 * @argc: Argument count, the number of command-line arguments
 * @argv: Argument vector, an array of strings containing the arguments
 *
 * Description: This program adds positive numbers provided as
 * command-line arguments.
 * If no numbers are provided, it prints 0. If any argument is not
 * a valid positive number,
 * it prints "Error" and returns 1. The program prints the sum of the
 * valid numbers and returns 0.
 *
 * Return: 0 for successful execution, 1 for an error.
 */
int main(int argc, char *argv[])
{
	int sum = 0;
	int i, j;

	if (argc == 1)
	{
		printf("%d\n", 0);
		return (0);
	}

	for (i = 0; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (!(isdigit(argv[i][j])))
		{
			printf("Error\n");
			return (1);
		}
		sum = sum + atoi(argv[i]);
		}
	}

	printf("%d\n", sum);

	return (0);
}

