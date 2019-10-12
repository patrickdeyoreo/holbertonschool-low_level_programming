#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>

/**
 * hash_chain_set - change an element in a singly-linked list
 * @head: a pointer to the singly-linked list
 * @key: a pointer to the element's key
 * @value: a pointer to the element's new value
 *
 * Return: 1 upon success, otherwise 0
 */
int hash_chain_set(hash_node_t *head, const char *key, char *value)
{
	if (head)
	{
		if (strcmp(key, head->key))
			return (hash_chain_set(head->next, key, value));

		free(head->value);
		head->value = value;
		return (1);
	}
	return (0);
}

/**
 * hash_table_set - set an element in a hash table
 * @ht: a pointer to the hash table
 * @key: a pointer to the element's key
 * @value: a pointer to the element's value
 *
 * Return: 1 upon success, otherwise 0
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node = NULL;
	char *new_value = NULL;
	unsigned long int index = 0;

	if (!(ht && key && *key))
		return (0);

	if (value)
	{
		new_value = strdup(value);
		if (!new_value)
			return (0);
	}

	index = key_index((const unsigned char *) key, ht->size);

	if (hash_chain_set(ht->array[index], key, new_value))
		return (1);

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
	{
		free(new_value);
		return (0);
	}

	new_node->key = strdup(key);
	if (!new_node->key)
	{
		free(new_value);
		free(new_node);
		return (0);
	}

	new_node->value = new_value;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
