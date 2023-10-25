#include "main.h"
int find_square_root(int n, int guess);
/**
 * _sqrt_recursion - Calculate the natural square root of a number.
 * @n: The number to find the square root of.
 *
 * Return: The natural square root of the number, or -1 if it doesn't exist.
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (find_square_root(n, 1));
}
/**
 * find_square_root - Helper function to find the square root recursively.
 * @n: The number to find the square root of.
 * @guess: The current guess for the square root.
 *
 * Return: The natural square root of the number, or -1 if it doesn't exist.
 */
int find_square_root(int n, int guess)
{
	if (guess * guess == n)
		return (guess);
	if (guess * guess > n)
		return (-1);
	return (find_square_root(n, guess + 1));
}

