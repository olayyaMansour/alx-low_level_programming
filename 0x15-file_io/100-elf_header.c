#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <stdarg.h>


/**
 * error_exit - handles errors and exits the program
 * @code: exit code to use
 * @msg: error message format string
 * @...: variable arguments for the format string
 */
void error_exit(int code, const char *msg, ...) {
	va_list args;
	va_start(args, msg);
	dprintf(STDERR_FILENO, msg, args);
	va_end(args);
	exit(code);
}

/**
 * print_elf_header - prints ELF header information
 * @ehdr: ELF header structure
 */
void print_elf_header(Elf64_Ehdr *ehdr) {
	int i;

	printf("ELF Header:\n");
	printf("	Magic:   ");
	for (i = 0; i < EI_NIDENT; ++i)
		printf("%02x%c", ehdr->e_ident[i], i + 1 < EI_NIDENT ? ' ' : '\n');

	printf("	Class:                             ");
	switch (ehdr->e_ident[EI_CLASS]) {
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", ehdr->e_ident[EI_CLASS]);
	}

	printf("	Data:                              %s\n", ehdr->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
		(ehdr->e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "<unknown>"));

	printf("	Version:                           %d (current)\n", ehdr->e_ident[EI_VERSION]);
	printf("	OS/ABI:                            %s\n", ehdr->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
		(ehdr->e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "UNIX - NetBSD" :
		(ehdr->e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "UNIX - Solaris" : "<unknown>")));

	printf("	ABI Version:                       %d\n", ehdr->e_ident[EI_ABIVERSION]);

	printf("	Type:                              %s\n", ehdr->e_type == ET_EXEC ? "EXEC (Executable file)" :
		(ehdr->e_type == ET_DYN ? "DYN (Shared object file)" : "<unknown>"));

	printf("	Entry point address:               %lx\n", (unsigned long)ehdr->e_entry);
}

/**
 * main - entry point of the program
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, otherwise appropriate error code
 */
int main(int argc, char *argv[]) {
	int fd;
	Elf64_Ehdr ehdr;

	if (argc != 2)
		error_exit(98, "Usage: elf_header elf_filename\n");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit(98, "Error: Cannot open file %s\n", argv[1]);

	if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr))
		error_exit(98, "Error: Cannot read ELF header from file %s\n", argv[1]);

	if (lseek(fd, 0, SEEK_SET) == -1)
		error_exit(98, "Error: Cannot rewind file %s\n", argv[1]);

	print_elf_header(&ehdr);

	close(fd);

	return (0);
}

