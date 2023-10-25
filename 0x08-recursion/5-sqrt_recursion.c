#include "main.h"
/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: The number for which to find the square root
 *
 * Return: The natural square root of n, or -1 if there's no natural square
 * root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n == 0 || n == 1)
	{
		return (n);
	}
	else
	{
		return (_sqrt_helper(n, 1, n));
	}
}

/**
 * _sqrt_helper - Recursive helper function to find the square root
 * @n: The number for which to find the square root
 * @low: The lower bound for binary search
 * @high: The upper bound for binary search
 *
 * Return: The natural square root of n, or -1 if there's no natural square
 * root
 */
int _sqrt_helper(int n, int low, int high)
{
	int mid, square;

	if (low <= high)
	{
		mid = (low + high) / 2;
		square = mid * mid;

		if (square == n)
		{
			return (mid);
		}
		else if (square < n)
		{
			return (_sqrt_helper(n, mid + 1, high));
		}
		else
		{
			return (_sqrt_helper(n, low, mid - 1));
		}
	}
	return (-1);
}
