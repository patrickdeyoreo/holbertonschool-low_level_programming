#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print_sep - print a separator between elements in a hash table
 */
void hash_table_print_sep(void)
{
	fputs(", ", stdout);
}

/**
 * hash_chain_print - print the elements in a singly-linked list
 * @head: a pointer to the singly-linked list
 */
void hash_chain_print(const hash_node_t *head)
{
	for (;;)
	{
		if (head->value)
			printf("'%s': '%s'", head->key, head->value);
		else
			printf("'%s': %s", head->key, head->value);

		head = head->next;

		if (head)
			hash_table_print_sep();
		else
			return;
	}
}

/**
 * hash_table_print - print the elements in a hash table
 * @ht: a pointer to the hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	void (*print_sep)() = NULL;
	hash_node_t **array = NULL;
	unsigned long int index = 0;
	unsigned long int size = 0;

	if (ht)
	{
		putchar('{');
		for (array = ht->array, size = ht->size; index < size; ++index)
		{
			if (array[index])
			{
				if (print_sep)
					print_sep();
				else
					print_sep = hash_table_print_sep;

				hash_chain_print(array[index]);
			}
		}
		puts("}");
	}
}
