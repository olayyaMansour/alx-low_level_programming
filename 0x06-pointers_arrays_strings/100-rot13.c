#include "main.h"

/**
 * rot13 - Encode a string using the ROT13 algorithm
 * @str: Pointer to the string to be encoded
 *
 * Return: A pointer to the resulting encoded string
 */
char *rot13(char *str)
{
	int i, j;
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (str[i] == alphabet[j])
			{
				str[i] = rot13[j];
				break;
			}
		}
	}
	return (str);
}

