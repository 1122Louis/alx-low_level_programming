#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table.
 *
 * @ht:  hash table  key/value to be added or update
 * @key: key
 * @value: value associated with the key
 * Return: 1 if it succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *hash_node;
	char *value_copy;
	unsigned long int index, i;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);
	index = key_index((unsigned char *)key, ht->size);
	for (i = index; ht->array[i]; i++)
	{
		if (strcmp(ht->array[i]->key, key) == 0)
		{
			free(ht->array[i]->value);
			ht->array[i]->value = value_copy;
			return (1);
		}
	}
	hash_node = malloc(sizeof(hash_node_t));
	if (hash_node == NULL)
	{
		free(value_copy);
		return (0);
	}
	hash_node->key = strdup(key);
	if (hash_node->key == NULL)
	{
		free(hash_node);
		return (0);
	}
	hash_node->value = value_copy;
	hash_node->next = ht->array[index];
	ht->array[index] = hash_node;
	return (1);
}
