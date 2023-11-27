#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 1024

void close_fd(int fd, const char *filename, int exit_code)
{
	dprintf(2, "Error: Can't close fd %d\n", fd);
	if (filename)
		dprintf(2, "Error: Can't read from file %s\n", filename);
	exit(exit_code);
}

void print_error(const char *msg, const char *filename, int exit_code)
{
	dprintf(2, "Error: %s %s\n", msg, filename);
	exit(exit_code);
}

int main(int argc, char *argv[])
{
	int fd_from, fd_to, rd_bytes, wr_bytes;
	char buffer[BUFSIZE];

	if (argc != 3)
		print_error("Usage: %s file_from file_to", NULL, 97);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		print_error("Can't read from file", argv[1], 98);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		print_error("Can't write to", argv[2],
				close_fd(fd_from, NULL, 99));

	while ((rd_bytes = read(fd_from, buffer, BUFSIZE)) > 0)
	{
		wr_bytes = write(fd_to, buffer, rd_bytes);
		if (wr_bytes == -1 || wr_bytes != rd_bytes)
			print_error("Can't write to", argv[2],
					close_fd(fd_from, fd_to, 99));
	}

	if (rd_bytes == -1)
		print_error("Can't read from file", argv[1],
			close_fd(fd_from, fd_to, 98));

	if (close(fd_from) == -1 || close(fd_to) == -1)
		close_fd(fd_from, fd_to, 100);

	return (0);
}

