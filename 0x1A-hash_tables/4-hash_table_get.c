#include "hash_tables.h"
#include <string.h>
#include <stdio.h>

/**
 * hash_table_get - get a value associated with a key
 * @ht: the hash table to search in
 * @key: the key to retreive
 * Return: value if key found, NULL if not or an error occurs
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *node;

	if (ht == NULL || !key)
		return (NULL);

	index = key_index((const unsigned char *) key, ht->size);

	node = ht->array[index];
	while (node != NULL && strcmp(node->key, key) != 0)
		node = node->next;

	if (node == NULL)
		return (NULL);

	return (node->value);
}
