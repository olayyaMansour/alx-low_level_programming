#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - Searches a string for any of a set of bytes.
 * @s: The string to search.
 * @accept: The set of characters to compare against.
 * Return: A pointer to the byte in 's', or NULL if not found.
 */
char *_strpbrk(char *s, char *accept)
{
	while (*s)
	{
		char *pAccept = accept;

		while (*pAccept)
		{
			if (*s == *pAccept)
				return (s);
			pAccept++;
		}
		s++;
	}
	return (NULL);
}

