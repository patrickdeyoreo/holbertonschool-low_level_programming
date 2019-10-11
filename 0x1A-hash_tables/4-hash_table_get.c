#include "hash_tables.h"
#include <string.h>

/**
 * _hash_table_get - get an element from a hash table (helper)
 * @head: pointer to a linked list
 * @key: the key of the element
 *
 * Return: a pointer to the element, or NULL if the key was not found
 */
char *_hash_table_get(const hash_node_t *head, const char *key)
{
	if (head)
	{
		if (strcmp(key, head->key))
			return (_hash_table_get(head->next, key));
		return (head->value);
	}
	return (NULL);
}

/**
 * hash_table_get - get an element from a hash table
 * @ht: pointer to a hash table
 * @key: the key of the desired element
 *
 * Return: a pointer to the element, or NULL if the key was not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	if (!(ht && key && *key))
		return (0);

	return (_hash_table_get(
		ht->array[key_index((const unsigned char *) key, ht->size)],
		key
	));
}
