#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_chain_delete - delete a singly-linked list
 * @head: a pointer to the head of the singly-linked list
 */
void hash_chain_delete(hash_node_t *head)
{
	if (head)
	{
		hash_chain_delete(head->next);
		free(head->key);
		free(head->value);
		free(head);
	}
}

/**
 * hash_table_delete - delete a hash table
 * @ht: a pointer to the hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t **array = NULL;
	unsigned long int index = 0;
	unsigned long int size = 0;

	if (ht)
	{
		for (array = ht->array, size = ht->size; index < size; ++index)
			hash_chain_delete(array[index]);

		free(ht->array);
		free(ht);
	}
}
