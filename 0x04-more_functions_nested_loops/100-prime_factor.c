#include <stdio.h>

/**
 * largest_prime_factor - Finds the largest prime factor of a number
 * @n: The number to find the largest prime factor of
 *
 * Return: The largest prime factor
 */
long largest_prime_factor(long n)
{
	long largest_factor = -1;

	while (n % 2 == 0)
	{
	largest_factor = 2;
	n = n / 2;
	}

	for (long i = 3; i <= n; i += 2)
	{
	while (n % i == 0)
	{
	largest_factor = i;
	n = n / i;
	}
	}

	return (largest_factor);
}
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	long num = 612852475143;
	long largest_factor = largest_prime_factor(num);

	printf("%ld\n", largest_factor);
	return (0);
}

