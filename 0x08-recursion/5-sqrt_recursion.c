#include "main.h"

int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return -1;
	}
	return _sqrt_helper(n, 1);
}

int _sqrt_helper(int n, int guess)
{
	int square = guess * guess;

	if (square == n)
	{
		return guess;
	}
	else if (square < n)
	{
		return _sqrt_helper(n, guess + 1);
	}
	else
	{
		return -1;
	}
}

