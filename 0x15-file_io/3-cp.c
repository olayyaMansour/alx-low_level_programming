#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

/**
 * error_exit - handles errors and exits the program
 * @code: exit code to use
 * @msg: error message to print
 */
void error_exit(int code, const char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
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
		error_exit(97, "Usage: cp file_from file_to");

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		error_exit(98, "Error: Can't read from file %s", argv[1]);

	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (file_to == -1)
		error_exit(99, "Error: Can't write to %s", argv[2]);

	do {
		r = read(file_from, buffer, BUFFER_SIZE);
		if (r == -1)
		error_exit(98, "Error: Can't read from file %s", argv[1]);

		w = write(file_to, buffer, r);
		if (w == -1)
			error_exit(99, "Error: Can't write to %s", argv[2]);
	} while (r > 0);

	if (close(file_from) == -1)
		error_exit(100, "Error: Can't close fd %d", file_from);
	if (close(file_to) == -1)
		error_exit(100, "Error: Can't close fd %d", file_to);

	return (0);
}

