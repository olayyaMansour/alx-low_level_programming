#include "main.h"

/**
 * _strcmp - Compares two strings
 * @s1: The first string to compare
 * @s2: The second string to compare
 *
 * Return: 0 if the strings are equal, a negative value if s1 < s2,
 * or a positive value if s1 > s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

