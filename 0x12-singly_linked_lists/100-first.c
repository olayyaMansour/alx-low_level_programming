#include <stdio.h>

/**
 * pre_main - Function to be executed before main.
 * Prints "You're beat! and yet, you must allow,\n
 * I bore my house upon my back!\n"
 * before the main function is executed.
 */
void __attribute__((constructor)) pre_main(void)
{
	printf("You're beat! and yet, you must allow,\n
		    I bore my house upon my back!\n");
}

