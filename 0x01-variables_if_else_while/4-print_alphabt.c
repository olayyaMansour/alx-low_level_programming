#include <stdio.h>
/**
 * main - prints the alphabet except q and e in lowercase
 *
 * Return: (0) success
 */
int main(void)
{
	char letter = 'a';

	while (letter <= 'z')
{
	if (letter != 'e' && letter != 'q')
	putchar(letter);
	letter++;
}
	putchar('\n');
	return (0);
}
