#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints buffer
 * @buffer: buffer
 * @size: size
 * Return: void
 */
void print_buffer(char *buffer, int size)
{
	int offset, j, i;

	offset = 0;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	while (offset < size)
	{
		j = size - offset < 10 ? size - offset : 10;
		printf("%08x: ", offset);
		for (i = 0; i < 10; i++)
		{
			if (i < j)
				printf("%02x", *(buffer + offset + i));
			else
				printf("  ");
			if (i % 2)
			{
				printf(" ");
			}
		}
		for (i = 0; i < j; i++)
		{
			int character = *(buffer + offset + i);

			if (character < 32 || character > 126)
			{
				character = '.';
			}
			printf("%c", character);
		}
		printf("\n");
		offset += 10;
	}
}

