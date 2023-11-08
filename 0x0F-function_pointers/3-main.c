#include "3-calc.h"
/**
 * main - Prints the opcodes of its own main function.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: 0 on success, or an exit code on error.
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;
	int (*operation)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	operation = get_op_func(argv[2]);

	if (!operation)
		return (99);

	result = operation(num1, num2);
	printf("%d\n", result);

	return (0);
}

