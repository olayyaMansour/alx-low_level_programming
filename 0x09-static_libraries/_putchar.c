#include "main.h"
#include <unistd.h>
/**
* _putchar - puts out the character c to the standart output
* @c: The character to print
*
* Return: 1 (Success)
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
