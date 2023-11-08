#include <stddef.h>

/**
 * int_index - searches for an integer in an array
 * @array: the array of integers to search
 * @size: the number of elements in the array
 * @cmp: a pointer to the comparison function
 *
 * Return: Index of the first element for which cmp function does not return 0.
 *         -1 if no element matches or if size is less than or equal to 0.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	if (array != NULL && cmp != NULL && size > 0)
	{
		int i;

		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]) != 0)
				return (i);
		}
	}

	return (-1);
}

