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
	(void)argv;

	printf("%d\n", argc - 1);

	return (0);
}

