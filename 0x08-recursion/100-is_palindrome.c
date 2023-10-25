#include "main.h"
#include <string.h>
int is_palindrome_helper(char *s, int start, int end);
/**
 * is_palindrome - Check if a string is a palindrome
 * @s: The string to check
 * @start: The starting index of the string (used for recursion)
 * @end: The ending index of the string (used for recursion)
 * 
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(char *s)
{
	return (is_palindrome_helper(s, 0, strlen(s) - 1));
}

/**
 * is_palindrome_helper - Helper function for recursive palindrome check
 * @s: The string to check
 * @start: The starting index of the substring (used for recursion)
 * @end: The ending index of the substring (used for recursion)
 * 
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome_helper(char *s, int start, int end)
{
	if (start >= end)
	return (1);

	if (s[start] != s[end])
	return (0);

	return (is_palindrome_helper(s, start + 1, end - 1));
}

