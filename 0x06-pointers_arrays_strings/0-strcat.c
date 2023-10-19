#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: The destination string to which src is appended
 * @src: The source string to be appended to dest
 *
 * Return: A pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	char *result = dest;

	while (*dest)
		dest++;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (result);
}

