#include "main.h"
/**
 * is_prime_number - Check if a number is prime
 * @n: The number to check
 *
 * Return: 1 if the number is prime, 0 otherwise
 */

int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}

	int divisor;

	for (divisor = 2; divisor < n; divisor++)
	{
		if (n % divisor == 0)
		{
			return (0);
		}
	}

	return (1);
}

