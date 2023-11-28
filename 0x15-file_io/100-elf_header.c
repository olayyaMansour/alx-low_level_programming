#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - handles errors and exits the program
 * @code: exit code to use
 * @msg: error message format string
 * @...: variable arguments for the format string
 */
void error_exit(int code, const char *msg, ...)
{
	va_list args;

	va_start(args, msg);
	dprintf(STDERR_FILENO, msg, args);
	va_end(args);
	exit(code);
}

/**
 * main - entry point of the program
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, otherwise appropriate error code
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, r, w;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to\n");

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", argv[1]);

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
	S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (file_to == -1)
		error_exit(99, "Error: Can't write to %s\n", argv[2]);

	do {
		r = read(file_from, buffer, BUFFER_SIZE);
		if (r == -1)
			error_exit(98, "Error: Can't read from file %s\n", argv[1]);

		w = write(file_to, buffer, r);
		if (w == -1)
			error_exit(99, "Error: Can't write to %s\n", argv[2]);
	} while (r > 0);

	if (close(file_from) == -1)
		error_exit(100, "Error: Can't close fd %d\n", file_from);
	if (close(file_to) == -1)
		error_exit(100, "Error: Can't close fd %d\n", file_to);

	return (0);
}

