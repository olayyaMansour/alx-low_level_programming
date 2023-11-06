#include "dog.h"
#include <stdio.h>

/**
 * print_dog - Prints the information of a struct dog
 * @d: Pointer to the struct dog to print
 */
void print_dog(struct dog *d)
{
	if (d)

	printf("Name: %s\n", d->name ? d->name : "(nil)");
	printf("Age: %.6f\n", d->age);
	printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
}

