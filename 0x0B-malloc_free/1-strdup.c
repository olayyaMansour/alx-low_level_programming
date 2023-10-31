#include <stdlib.h>
/**
 * _strdup - Returns a pointer to a newly allocated space in memory
 * containing a copy of the string given as a parameter.
 * @str: The string to duplicate.
 *
 * Return: If str is NULL or if memory allocation fails, returns NULL.
 */

char *_strdup(char *str)
{
	char *dup_str;
	int length = 0, i;

	if (str == NULL)
		return (NULL);

	while (str[length])
		length++;

	dup_str = (char *)malloc(sizeof(char) * (length + 1));

	if (dup_str == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
		dup_str[i] = str[i];

	return (dup_str);
}

