#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point of the program
 * @argc: Argument count, the number of command-line arguments
 * @argv: Argument vector, an array of strings containing the arguments
 *
 * Description: This program multiplies two numbers and prints the result.
 * If the program does not receive exactly two arguments
 * (including the program name),
 * it prints "Error" and returns 1. Otherwise, it performs the multiplication,
 * prints the result, and returns 0.
 *
 * Return: 0 for successful execution, 1 for an error.
 */
int main(int argc, char *argv[])
{
	int result;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	result = atoi(argv[1]) * atoi(argv[2]);
	printf("%d\n", result);

	return (0);
}

