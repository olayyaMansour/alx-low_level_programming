#include "main.h"

int is_prime_number(int n)
{
	if (n <= 1)
	{
		return 0;
	}

	int divisor;
	for (divisor = 2; divisor < n; divisor++)
	{
		if (n % divisor == 0)
		{
			return 0;
		}
	}

	return (1);
}

