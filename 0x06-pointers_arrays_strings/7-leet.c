#include "main.h"

/**
 * leet - Encodes a string into 1337
 * @str: The string to be encoded
 *
 * Return: A pointer to the resulting string
 */
char *leet(char *str)
{
	char *result = str;
	char leet_chars[] = "aAeEoOtTlL";
	char leet_map[] = "44370171";
	int i, j;

	while (*str)
	{
		i = 0;
		while (leet_chars[i])
		{
			if (*str == leet_chars[i])
			{
				*str = leet_map[i];
				break;
			}
			i++;
		}
		str++;
	}

	return (result);
}

