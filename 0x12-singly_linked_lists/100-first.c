#include <stdio.h>

/**
 * myStartupFun - function to be executed before main
 */
void myStartupFun(void) __attribute__((constructor));

/**
 * myStartupFun - function to be executed before main
 */
void myStartupFun(void)
{
	printf("You're beat! and yet, you must allow,\n
			I bore my house upon my back!\n");
}

