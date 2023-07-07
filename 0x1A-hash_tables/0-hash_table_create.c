#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_create - create a hash table data structure
 * @size: size of the hash table (slots/buckets)
 * Return: pointer to list or NULL if failed
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int i;
	hash_table_t *ht;

	if (size <= 0)
		return (NULL);

	ht = (hash_table_t *) malloc(sizeof(hash_table_t));

	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = (hash_node_t **) malloc(sizeof(hash_node_t *) * size);

	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		ht->array[i] = NULL;
	}

	return (ht);
}
