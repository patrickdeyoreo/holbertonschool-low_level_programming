#include "hash_tables.h"
#include <string.h>

/**
 * hash_chain_get - get an element from a singly-linked list
 * @head: a pointer to the singly-linked list
 * @key: a pointer to the element's key
 *
 * Return: a pointer to the element's value, or NULL if the key wasn't found
 */
char *hash_chain_get(const hash_node_t *head, const char *key)
{
	if (head)
	{
		if (strcmp(key, head->key))
			return (hash_chain_get(head->next, key));

		return (head->value);
	}
	return (NULL);
}

/**
 * hash_table_get - get an element from a hash table
 * @ht: a pointer to the hash table
 * @key: a pointer to the element's key
 *
 * Return: a pointer to the element's value, or NULL if the key wasn't found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index = 0;

	if (ht && key && *key)
	{
		index = key_index((const unsigned char *) key, ht->size);
		return (hash_chain_get(ht->array[index], key));
	}
	return (0);
}
