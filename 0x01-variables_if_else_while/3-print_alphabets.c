#include <stdio.h>
/**
 * main - prints the alphabet in lowercase and then in uppercase
 *
 * Return: (0) success
 */
int main(void)
{
	char letter = 'a';
	char Letter = 'A';

	while (letter <= 'z')
{
	putchar(letter);
	letter++;
}
	while (Letter <= 'Z')
{
	putchar(Letter);
	Letter++;
}
	putchar('\n');
	return (0);
}
