#include "function_pointers.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * main - Prints the opcodes of its own main function.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: 0 on success, or an exit code on error.
 */
int main(int argc, char *argv[])
{
	char *p = (char *)main;
	int num_bytes;

	if (argc != 2)
	{
		printf("Error\n"), exit(1);
	}

	num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n"), exit(2);
	}

	while (num_bytes--)
		printf("%02hhx%s", *p++, num_bytes ? " " : "\n");
	return (0);
}
