#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * shash_table_create - create a sorted hash table
 * @size: size of the hash table
 * Return: pointer to the hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int i;
	shash_table_t *ht;

	if (size <= 0)
		return (NULL);

	ht = (shash_table_t *) malloc(sizeof(shash_table_t));

	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = (shash_node_t **) malloc(sizeof(shash_node_t *) * size);

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

/**
 * sadd_node - add a new node to the beginning of a shash_node_t list
 * @head: beginning of list
 * @key: key of the hash element
 * @value: value of the hash element
 * @result: insert location - 1: head, 2: center, 3: tail, 0: failure
 * Return: address of the new element, NULL on failure
 */
shash_node_t *sadd_node(shash_node_t **head, const char *key,
						const char *value, int *result)
{
	shash_node_t *new, *node, *last_node;
	int index = 0;

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
		return (NULL);
	new->key = strdup(key);
	new->value = strdup(value);
	if (*head == NULL)
	{
		new->sprev = NULL;
		new->next = NULL;
		new->snext = NULL;
		*head = new;
		*result = 1;
		return (new);
	}
	for (node = *head; node; index += 1, node = node->next)
	{
		if (strcmp(value, node->key) < 0)
		{
			new->next = node;
			new->snext = node;
			new->sprev = node->sprev;
			node->sprev = new;
			if (index == 0)
				*head = new;
			*result = 2;
			return (new);
		}
		last_node = node;
	}
	new->next = NULL;
	new->snext = NULL;
	new->sprev = last_node;
	*result = 3;
	return (new);
}

/**
 * shash_table_set - add an element to a hash table
 * @ht: hash table to add to
 * @key: index to add element in the hash table
 * @value: value of the element
 * Return: 1 if succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	shash_node_t *node = NULL, *tmp, *ret_node;
	int result = 1;

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

	ret_node = sadd_node(&node, key, value, &result);

	ht->array[index] = ret_node;

	if (result == 0)
		return (0);
	if (result == 1)
		ht->shead = ret_node;
	if (result == 3)
		ht->stail = ret_node;
	return (1);
}

/**
 * shash_table_get - get a value associated with a key
 * @ht: the hash table to search in
 * @key: the key to retreive
 * Return: value if key found, NULL if not or an error occurs
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;

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

/**
 * shash_table_print - prints a hash table
 * @ht: hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node = NULL;
	unsigned long int i = 0;
	int count = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			printf("'%s':'%s', ", node->key, node->value);
			node = node->next;
			count += 1;
		}
	}

	if (count)
		printf("\b\b");

	printf("}\n");
}

/**
 * shash_table_print_rev - prints a hash table in reverse
 * @ht: hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node = NULL;
	unsigned long int i = 0;
	int count = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (i = ht->size - 1; ; i--)
	{
		node = ht->array[i];
		while (node)
		{
			printf("'%s':'%s', ", node->key, node->value);
			count += 1;
			node = node->sprev;
		}
		if (i == 0)
			break;
	}

	if (count)
		printf("\b\b");

	printf("}\n");
}

/**
 * shash_table_delete - deletes and frees a hash table
 * @ht: hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *next;
	unsigned long int i;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			next = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = next;
		}
	}
	free(ht->array);
	free(ht);
	ht = NULL;
}

