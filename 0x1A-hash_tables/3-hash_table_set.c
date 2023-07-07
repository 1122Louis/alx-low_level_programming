#include "hash_tables.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * hash_table_set - add an element to a hash table
 * @ht: hash table to add to
 * @key: index to add element in the hash table
 * @value: value of the element
 * Return: 1 if succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	hash_node_t *node = NULL, *tmp, *result;

	if (strlen(key) == 0)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = node = ht->array[index];

	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = strdup(value);
			if (tmp->value == NULL)
				return (0);
			return (1);
		}
		tmp = tmp->next;
	}

	result = add_node(&node, key, value);

	if (result == NULL)
		return (0);

	ht->array[index] = result;

	return (1);
}

/**
 * add_node - add a new node to the beginning of a hash_node_t list
 * @head: beginning of list
 * @key: key of the hash element
 * @value: value of the hash element
 * Return: address of the new element, NULL on failure
 */
hash_node_t *add_node(hash_node_t **head, const char *key, const char *value)
{
	hash_node_t *new;

	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
		return (NULL);

	new->key = strdup(key);
	new->value = strdup(value);
	if (new->key == NULL || new->value == NULL)
	{
		free(new);
		return (NULL);
	}

	new->next = *head;

	*head = new;

	return (new);
}
