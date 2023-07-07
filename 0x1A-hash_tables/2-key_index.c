#include "hash_tables.h"

/**
 * key_index - get the index of a key value
 * @key: the key
 * @size: size of the hash table array
 * Return: index within 0 and @size (exclusive)
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash;

	hash = hash_djb2(key);

	return (hash % size);
}
