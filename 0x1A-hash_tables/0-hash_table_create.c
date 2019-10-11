#include "hash_tables.h"

/**
 * hash_table_create - create a new hash table
 * @size: the size of the new hash table
 *
 * Return: a pointer to a newly created hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht = malloc(sizeof(*ht));

	if (ht)
	{
		ht->array = calloc(size, sizeof(void *));
		if (ht->array)
			ht->size = size;
		else
			free(ht);
	}
	return (ht);
}
