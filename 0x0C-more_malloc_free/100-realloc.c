#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _realloc - Reallocate memory for a block previously allocated with malloc.
 * @ptr: Pointer to the previously allocated memory block.
 * @old_size: The size, in bytes, of the old memory block.
 * @new_size: The new size, in bytes, of the memory block.
 *
 * Return: A pointer to the newly allocated memory, or NULL on failure.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return (NULL);

	if (new_size > old_size)
		new_size = old_size;

	memcpy(new_ptr, ptr, new_size);
	free(ptr);

	return (new_ptr);
}

