#include "main.h"

/**
 * string_toupper - Converts lowercase letters in a string to uppercase
 * @str: The string to be converted
 *
 * Return: A pointer to the resulting string
 */
char *string_toupper(char *str)
{
	char *result = str;

	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
	return (result);
}

