#include "hash_tables.h"
#include <string.h>

/**
 * _hash_table_set - set an element in a hash table (helper)
 * @head: pointer to a linked list
 * @key: the key of the element
 * @new_value: the element
 *
 * Return: 1 upon success, otherwise 0
 */
int _hash_table_set(hash_node_t *head, const char *key, char *new_value)
{
	if (head)
	{
		if (!strcmp(key, head->key))
		{
			free(head->value);
			head->value = new_value;
			return (1);
		}
		return (_hash_table_set(head->next, key, new_value));
	}
	return (0);
}

/**
 * hash_table_set - set an element in a hash table
 * @ht: pointer to a hash table
 * @key: the key of the element
 * @value: the element
 *
 * Return: 1 upon success, otherwise 0
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node = NULL;
	char *new_value = NULL;
	unsigned long int idx = 0;

	if (!(ht && key && *key))
		return (0);

	if (value)
	{
		new_value = strdup(value);
		if (!new_value)
			return (0);
	}

	idx = key_index((const unsigned char *) key, ht->size);
	if (_hash_table_set(ht->array[idx], key, new_value))
		return (1);

	new_node = malloc(sizeof(new_node));
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
	new_node->next = ht->array[idx];
	ht->array[idx] = new_node;
	return (1);
}
