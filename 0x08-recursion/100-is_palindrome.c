#include "main.h"
int check_palindrome(char *s, int start, int end);
/**
 * is_palindrome - Check if a string is a palindrome.
 * @s: The string to check.
 *
 * Return: 1 if it's a palindrome, 0 if it's not.
 */

int is_palindrome(char *s)
{
	int length = _strlen(s);

	return (check_palindrome(s, 0, length - 1));
}
/**
 * _strlen - Calculate the length of a string.
 * @s: The string to calculate the length of.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen(s + 1));
}
/**
 * check_palindrome - Check if a substring is a palindrome.
 * @s: The string to check.
 * @start: The start index of the substring.
 * @end: The end index of the substring.
 *
 * Return: 1 if it's a palindrome, 0 if it's not.
 */
int check_palindrome(char *s, int start, int end)
{
	if (start >= end)
		return (1);

	if (s[start] != s[end])
		return (0);

	return (check_palindrome((s, start + 1, end - 1)));
}

