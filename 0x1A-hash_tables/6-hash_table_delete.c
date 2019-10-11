#include "hash_tables.h"

/**
 * _hash_table_delete - delete a hash table
 * @head: pointer to a linked list
 */
void _hash_table_delete(hash_node_t *head)
{
	if (head)
	{
		_hash_table_delete(head->next);
		free(head->key);
		free(head->value);
		free(head);
	}
}

/**
 * hash_table_delete - delete a hash table
 * @ht: a pointer to a hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t **array = NULL;
	unsigned int index = 0, size = 0;

	if (!ht)
		return;

	for (array = ht->array, size = ht->size; index < size; ++index)
		_hash_table_delete(array[index]);

	free(ht->array);
	free(ht);
}
