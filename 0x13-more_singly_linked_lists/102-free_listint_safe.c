#include "lists.h"
/**
 * free_listint_safe - Frees a listint_t list safely.
 * @h: A pointer to the head of the linked list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	listint_t *current, *temp;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	while (current != NULL)
	{
		size++;
		temp = current->next;

		if (current->next >= current)
		{
			*h = NULL;
			free(current);
			break;
		}

		current->next = current;

		current = temp;
	}

	return (size);
}

