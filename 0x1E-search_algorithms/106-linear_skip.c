#include <math.h>
#include "search_algos.h"

/**
* jump_list - Searches for a value in a sorted singly
* linked list using jump search.
* @list: Pointer to the head of the list to search in.
* @size: Number of nodes in the list.
* @value: The value to search for.
*
* Return: Pointer to the first node where value is located,
* or NULL if not found.
*/
listint_t *jump_list(listint_t *list, size_t size, int value)
{
size_t jump = sqrt(size);
listint_t *prev = list;
listint_t *curr = list;
size_t i;

if (list == NULL || size == 0)
return (NULL);

while (curr->index < size - 1 && curr->n < value)
{
prev = curr;
for (i = 0; i < jump && curr->next; i++)
curr = curr->next;

printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);

if (curr->n >= value)
break;
}

printf("Value found between indexes [%lu] and [%lu]\n",
	prev->index, curr->index);

while (prev != NULL && prev->index <= curr->index)
{
printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);

if (prev->n == value)
return (prev);

prev = prev->next;
}

return (NULL);
}
