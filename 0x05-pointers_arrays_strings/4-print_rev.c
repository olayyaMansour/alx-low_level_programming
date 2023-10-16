#include "main.h"

/**
 * print_rev - Prints a string in reverse followed by a new line.
 * @s: Pointer to the string.
 */
void print_rev(char *s)
{
	int lenght = 0;

	while (s[lenght] != '\0')
		lenght++;

	for (int i = lenght - 1; i >= 0; i--)
		_putchar(s[i]);

	_putchar('\n');
}
