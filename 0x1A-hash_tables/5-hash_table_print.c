#include "hash_tables.h"

/**
 * _hash_table_print - print all entries in a hash table (helper)
 * @head: pointer to linked list
 */
void _hash_table_print(const hash_node_t *head)
{
	for (;;)
	{
		printf("'%s': ", head->key);

		if (head->value)
			printf("'%s'", head->value);
		else
			printf("%s", head->value);

		head = head->next;

		if (head)
			printf(", ");
		else
			break;
	}
}

/**
 * hash_table_print - print all entries in a hash table
 * @ht: pointer to a hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t **array = NULL;
	unsigned long int index = 0, size = 0;
	unsigned char flag = 0;

	if (!ht)
		return;

	printf("{");
	for (array = ht->array, size = ht->size; index < size; ++index)
	{
		if (array[index])
		{
			if (flag)
				printf(", ");
			else
				flag = 1;

			_hash_table_print(array[index]);
		}
	}
	printf("}\n");
}
