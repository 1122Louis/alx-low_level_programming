#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"


/**
 *listint_len - Returns the number of elements
 *in a linked listint_t list
 *@h: A pointer to the head of the list
 *
 *
 *Return: the number of elements in the listint_t list
 */

size_t listint_len(const listint_t *h)
{
	size_t count_nodes = 0;

	while (h)
	{
		count_nodes++;
		h = h->next;
	}
	return (count_nodes);
}

