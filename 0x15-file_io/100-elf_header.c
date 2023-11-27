#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

#define BUF_SIZE 1024

void print_error(const char *msg) {
    dprintf(2, "%s\n", msg);
    exit(98);
}

void read_elf_header(int fd) {
    Elf64_Ehdr header;
    int i;

    if (read(fd, &header, sizeof(header)) != sizeof(header))
        print_error("Error reading ELF header");

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x%c", header.e_ident[i], i + 1 < EI_NIDENT ? ' ' : '\n');
    printf("  Class:                             %s\n", header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
    printf("  Data:                              %s\n", header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %s\n", header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "unknown");
    printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
    printf("  Type:                              %s\n", header.e_type == ET_EXEC ? "EXEC (Executable file)" : "unknown");
    printf("  Entry point address:               0x%lx\n", (unsigned long)header.e_entry);
}

int main(int argc, char *argv[]) {
    int fd;

    if (argc != 2) {
        print_error("Usage: elf_header elf_filename");
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        print_error("Error: Can't open file");
    }

    read_elf_header(fd);

    if (close(fd) == -1) {
        print_error("Error: Can't close file descriptor");
    }

    return 0;
}

