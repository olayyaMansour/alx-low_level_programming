#include "main.h"
/**
 * reverse_string - reverses a string
 * @str: string to reverse
 */
void reverse_string(char *str)
{
	int length = 0;
	int start = 0;
	char temp;

	while (*(str + length) != '\0')
	{
		length++;
	}
	length--;

	for (start = 0; start < length; start++, length--)
	{
		temp = *(str + start);
		*(str + start) = *(str + length);
		*(str + length) = temp;
	}
}
/**
 * infinite_add - Add two numbers
 * @n1: The first number as a string
 * @n2: The second number as a string
 * @r: The buffer to store the result
 * @size_r: The buffer size
 * Return: A pointer to the result or 0 if the result cannot be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int carry = 0, i = 0, j = 0;
	int result_digits = 0;
	int value1 = 0;
	int value2 = 0;
	int temp_sum = 0;

	while (*(n1 + i) != '\0')
		i++;
	while (*(n2 + j) != '\0')
		j++;
	i--;
	j--;
	if (j >= size_r || i >= size_r)
		return (0);
	while (j >= 0 || i >= 0 || carry == 1)
	{
		if (i < 0)
			value1 = 0;
		else
			value1 = *(n1 + i) - '0';
		if (j < 0)
			value2 = 0;
		else
			value2 = *(n2 + j) - '0';
		temp_sum = value1 + value2 + carry;
		if (temp_sum >= 10)
			carry = 1;
		else
			carry = 0;
		if (result_digits >= (size_r - 1))
			return (0);
	*(r + result_digits) = (temp_sum % 10) + '0';
	result_digits++;
	j--;
	i--; }
	if (result_digits == size_r)
	return (0);
	*(r + result_digits) = '\0';
	reverse_string(r);
	return (r);
}

