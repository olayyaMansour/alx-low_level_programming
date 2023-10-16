#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: Pointer to the string.
 *
 * Return: The converted integer.
 */
int _atoi(char *s)
{
	unsigned long result = 0;
	int sign = 1;
	int i = 0;

	if (s[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i] != '\0')
	{

	if (s[0] == '+')
	{
		i++;
	}
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result = result * 10 + (s[i] - '0');
		}
		else
		{
			break;
		}
		i++;
	}

	if (result > INT_MAX && sign == 1)
		return (INT_MAX);

	if (result > INT_MAX && sign == -1)
		return (INT_MIN);

	return ((int)(sign * result));
}
