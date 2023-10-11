#include "main.h"
#include <stdio.h>
/**
 * positive_or_negative - checkes if number if positive or negative
 * @i: number to be checked
 */
void positive_or_negative(int i)
{
	if (i == 0)
		printf("%d is zero\n", i);
	else if (i > 0)
		printf("%d is positive\n", i);
	else
		printf("%d is negative\n", i);
}
