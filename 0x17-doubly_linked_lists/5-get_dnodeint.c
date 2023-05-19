#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * get_dnodeint_at_index - returns a node at a certain index
 * @head: doubly linked list
 * @index: index to get
 * Return: the node address, NULL if doesn't exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *p = head;
	unsigned int idx = 0;

	while (p && idx != index)
	{
		p = p->next;
		idx++;
	}

	return (p);
}
