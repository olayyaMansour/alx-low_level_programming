#include <stdio.h>
/**
 * main - Entry point of the program
 * @argc: Argument count, the number of command-line arguments
 * @argv: Argument vector, an array of strings containing the arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	for (int i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}

