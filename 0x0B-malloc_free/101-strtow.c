#include <stdlib.h>
/**
 * is_space - Checks if a character is a space, tab, or newline.
 * @c: The character to check.
 *
 * Return: 1 if it is a space, tab, or newline, 0 otherwise.
 */
int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}
/**
 * count_words - Counts the number of words in a string.
 * @str: The string to count words from.
 *
 * Return: The number of words in the string.
 */
int count_words(char *str)
{
	int count = 0, is_word = 0;

	while (*str)
	{
	if (is_space(*str))
	{
	is_word = 0;
	}
	else if (!is_word)
	{
	is_word = 1;
	count++;
	}
	str++;
	}
	return (count);
}
/**
 * duplicate_word - Creates a duplicate of a word from a string.
 * @str: The string containing the word.
 *
 * Return: A newly allocated string containing the word, or NULL on failure.
 */
char *duplicate_word(char *str)
{
	char *word;
	int len = 0;

	while (str[len] && !is_space(str[len]))
	{
	len++;
	}
	word = (char *)malloc(len + 1);

	if (word)
	{
	int i;

	for (i = 0; i < len; i++)
	{
	word[i] = str[i];
	}
	word[len] = '\0';
	}

	return (word);
}
/**
 * strtow - Splits a string into words.
 * @str: The string to split.
 *
 * Return: A pointer to an array of strings (words).
 */
char **strtow(char *str)
{	int words, i;
	char **word_array;

	if (!str || !*str)
	return (NULL);
	words = count_words(str);
	if (words == 0)
	return (NULL);
	word_array = (char **)malloc(sizeof(char *) * (words + 1));
	if (word_array)
	{
	int j, in_word = 0;

	for (i = 0, j = 0; str[i]; i++)
	{
	if (!is_space(str[i]))
	{
	if (!in_word)
	{
		word_array[j] = duplicate_word(str + i);
	in_word = 1;
	if (!word_array[j])
	{
		while (j >= 0)
	{
		free(word_array[j]);
	j--;
	}
	free(word_array);
	return (NULL);
	}
	j++;
	}} else
	{
		in_word = 0;
	}
	}
	word_array[words] = NULL;
	}
	return (word_array);
}
