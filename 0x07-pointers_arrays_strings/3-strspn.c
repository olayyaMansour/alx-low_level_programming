#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring.
 * @s: The string to search.
 * @accept: The set of characters to compare against.
 * Return: The number of bytes in the initial segment of 's' consisting
 * only of characters from 'accept'.
*/
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int found;
	char *pAccept;

	while (*s)
	{
		found = 0;
		pAccept = accept;
		while (*pAccept)
		{
			if (*s == *pAccept)
			{
				count++;
				found = 1;
				break;
			}
			pAccept++;
		}
		if (!found)
			return (count);
		s++;
	}
	return (count);
}

