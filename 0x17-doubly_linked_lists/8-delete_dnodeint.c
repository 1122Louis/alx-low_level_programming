#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - delete a node at an index
 * @head: doubly linked list
 * @index: index to insert node at
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int i = 0;
	dlistint_t *h = *head;

	for (; h && i < index; i++)
		h = h->next;

	if (i != index || h == NULL)
		return (-1);

	if (h->next)
		h->next->prev = h->prev;
	if (h->prev)
		h->prev->next = h->next;
	else
		*head = h->next;
	free(h);

	return (1);
}
