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
	char leet_replacements[] = "44370171";

	while (*str)
	{
		int i = 0;

		while (leet_chars[i])
		{
			if (*str == leet_chars[i])
			{
				*str = leet_replacements[i];
				break;
			}
			i++;
		}

	str++;
	}

	return (result);
}

