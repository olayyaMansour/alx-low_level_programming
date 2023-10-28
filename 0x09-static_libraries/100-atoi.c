#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: The input string.
 *
 * Return: The integer converted from the string.
 */
int _atoi(char *s)
{
	int i = 0;
	int num = 0;
	int len = 0;
	int negative_count = 0;
	int digit = 0;
	int found_digit = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && !found_digit)
	{
		if (s[i] == '-')
			negative_count++;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (negative_count % 2)
				digit = -digit;
			num = num * 10 + digit;
			found_digit = 1;

			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			found_digit = 0;
		}
		i++;
	}
	if (!found_digit)
		return (0);
	return (num);
}

