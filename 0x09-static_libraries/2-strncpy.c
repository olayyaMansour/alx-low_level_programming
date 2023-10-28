#include "main.h"

/**
 * _strncpy - Copies a string from src to dest with a specified maximum length
 * @dest: The destination string where the copied string is placed
 * @src: The source string to be copied
 * @n: The maximum number of characters to copy
 *
 * Return: A pointer to the resulting string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *result = dest;

	while (*src && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	while (n > 0)
	{
		*dest = '\0';
		dest++;
		n--;
	}
	return (result);
}

