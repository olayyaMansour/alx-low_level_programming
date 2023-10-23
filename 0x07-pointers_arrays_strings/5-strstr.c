#include "main.h"
#include <stddef.h>

/**
 * _strstr - Locates a substring.
 * @haystack: The string to search.
 * @needle: The substring to search for.
 * Return: A pointer to the beginning of the located substring, or
 * NULL if not found.
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		char *hay = haystack;
		char *nee = needle;

		while (*nee && *hay == *nee)
		{
			hay++;
			nee++;
		}

		if (*nee == '\0')
			return (haystack);

		haystack++;
	}

	return (NULL);
}

