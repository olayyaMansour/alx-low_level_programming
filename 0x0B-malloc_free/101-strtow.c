#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: The string to count words from.
 *
 * Return: The number of words in the string.
 */
int count_words(char *str) {
	int count = 0;
	int in_word = 0;

	while (*str) {
		if (*str == ' ') {
			if (in_word)
				in_word = 0;
		} else {
			if (!in_word) {
				count++;
				in_word = 1;
			}
		}
		str++;
	}

	return (count);
}

/**
 * strtow - Splits a string into words.
 * @str: The string to split.
 *
 * Return: A pointer to an array of strings (words).
 */
char **strtow(char *str) {
	int words, i, j, k;
	char **word_array;
	char *word;
	int in_word = 0;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	words = count_words(str);

	word_array = (char **)malloc((words + 1) * sizeof(char *));
	if (word_array == NULL)
		return (NULL);

	for (i = 0; i < words; i++) {
		while (*str == ' ' && *str != '\0')
			str++;

		in_word = 0;
		for (j = 0; str[j] != ' ' && str[j] != '\0'; j++)
			in_word++;

		word = (char *)malloc((in_word + 1) * sizeof(char));
		if (word == NULL) {
			for (k = i; k >= 0; k--)
				free(word_array[k]);
			free(word_array);
			return (NULL);
		}

		for (k = 0; k < in_word; k++)
			word[k] = str[k];
		word[k] = '\0';
		word_array[i] = word;
		str += in_word;
	}

	word_array[i] = NULL;
	return (word_array);
}

/**
 * print_tab - Prints an array of strings.
 * @tab: The array to print.
 */
void print_tab(char **tab) {
	int i;

	for (i = 0; tab[i] != NULL; ++i) {
		printf("%s\n", tab[i]);
	}
}

/**
 * main - Check the code for ALX School students.
 *
 * Return: 1 if an error occurred, 0 otherwise.
 */
int main(void) {
	char **tab;

	tab = strtow("      ALX School         #cisfun      ");
	if (tab == NULL) {
		printf("Failed\n");
		return (1);
	}
	print_tab(tab);
	return (0);
}

