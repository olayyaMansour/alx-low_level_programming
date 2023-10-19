#include "main.h"

/**
 * leet - Encodes a string into 1337
 * @str: The string to be encoded
 *
 * Return: A pointer to the resulting string
 */
char *leet(char *str)
{
	char s1[] = "aAeEoOtTlL";
	char s2[] = "44370171";
	int i, j;

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (str[i] == s1[j])
			{
				str[i] = s2[j];
			}
		}
	}
	return (str);
}
