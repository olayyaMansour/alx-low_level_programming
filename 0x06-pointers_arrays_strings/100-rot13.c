#include "main.h"

/**
 * rot13 - Encodes a string using ROT13
 * @str: The string to be encoded
 *
 * Return: A pointer to the resulting string
 */
char *rot13(char *str)
{
	char *result = str;
	char *letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	while (*str)
	{
		int i = 0;
		int replaced = 0;

	while (letters[i])
	{
		if (*str == letters[i])
		{
			*str = rot13[i];
			replaced = 1;
			break;
		}
		i++;
	}
	if (!replaced)
	{
		str++;
	}
	}

	return (result);
}

