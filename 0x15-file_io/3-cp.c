#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 1024

/**
 * main - Copies the content of a file to another file.
 * @argc: The argument count.
 * @argv: The argument vector.
 *
 * Return: 0 on success, otherwise the appropriate exit code.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, rd_bytes, wr_bytes;
	char buffer[BUFSIZE];

	if (argc != 3)
	{
		dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{ dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		exit(98); }
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{ dprintf(2, "Error: Can't write to %s\n", argv[2]);
		close(fd_from);
		exit(99); }
	while ((rd_bytes = read(fd_from, buffer, BUFSIZE)) > 0)
	{
		wr_bytes = write(fd_to, buffer, rd_bytes);
		if (wr_bytes == -1 || wr_bytes != rd_bytes)
		{ dprintf(2, "Error: Can't write to %s\n", argv[2]);
			close(fd_from);
			close(fd_to);
			exit(99); } }
	if (rd_bytes == -1)
	{ dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		close(fd_from);
		close(fd_to);
		exit(98); }
	if (close(fd_from) == -1)
	{ dprintf(2, "Error: Can't close fd %d\n", fd_from);
		exit(100); }
	if (close(fd_to) == -1)
	{ dprintf(2, "Error: Can't close fd %d\n", fd_to);
		exit(100); }
	return (0); }

