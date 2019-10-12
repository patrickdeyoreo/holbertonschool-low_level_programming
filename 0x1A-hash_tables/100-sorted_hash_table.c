#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * shash_table_create - create a hash table
 * @size: the desired size of the new hash table
 *
 * Return: a pointer to the newly created hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht = malloc(sizeof(*ht));

	if (ht)
	{
		ht->array = calloc(size, sizeof(*ht->array));
		if (ht->array)
		{
			ht->size = size;
			ht->shead = NULL;
			ht->stail = NULL;
			return (ht);
		}
		free(ht);
	}
	return (NULL);
}

/**
 * shash_chain_set - change an element in a singly-linked list
 * @head: a pointer to the singly-linked list
 * @key: a pointer to the element's key
 * @value: a pointer to the element's new value
 *
 * Return: 1 upon success, otherwise 0
 */
int shash_chain_set(shash_node_t *head, const char *key, char *value)
{
	if (head)
	{
		if (strcmp(key, head->key))
			return (shash_chain_set(head->next, key, value));

		free(head->value);
		head->value = value;
		return (1);
	}
	return (0);
}

/**
 * shash_list_insert - insert a node in a hash table's doubly-linked list
 * @ht: a pointer to the hash table
 * @snode: a pointer to the new node
 */
void shash_list_insert(shash_table_t *ht, shash_node_t *snode)
{
	shash_node_t *shead = ht->shead;
	shash_node_t *sprev = NULL;

	if (!shead)
	{
		ht->shead = snode;
		ht->stail = snode;
		snode->sprev = NULL;
		snode->snext = NULL;
	}
	else if (strcmp(shead->key, snode->key) > 0)
	{
		ht->shead = snode;
		snode->sprev = NULL;
		snode->snext = shead;
		shead->sprev = snode;
	}
	else
	{
		do {
			sprev = shead;
			shead = shead->snext;
		} while (shead && strcmp(shead->key, snode->key) < 0);

		snode->sprev = sprev;
		sprev->snext = snode;
		snode->snext = shead;
		if (shead)
			shead->sprev = snode;
		else
			ht->stail = snode;
	}
}

/**
 * shash_table_set - set an element in a hash table
 * @ht: a pointer to the hash table
 * @key: a pointer to the element's key
 * @value: a pointer to the element's value
 *
 * Return: 1 upon success, otherwise 0
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node = NULL;
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

	if (shash_chain_set(ht->array[index], key, new_value))
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
	shash_list_insert(ht, new_node);
	return (1);
}

/**
 * shash_chain_get - get an element from a singly-linked list
 * @head: a pointer to the singly-linked list
 * @key: a pointer to the element's key
 *
 * Return: a pointer to the element's value, or NULL if the key wasn't found
 */
char *shash_chain_get(const shash_node_t *head, const char *key)
{
	if (head)
	{
		if (strcmp(key, head->key))
			return (shash_chain_get(head->next, key));

		return (head->value);
	}
	return (NULL);
}

/**
 * shash_table_get - get an element from a hash table
 * @ht: a pointer to the hash table
 * @key: a pointer to the element's key
 *
 * Return: a pointer to the element's value, or NULL if the key wasn't found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index = 0;

	if (ht && key && *key)
	{
		index = key_index((const unsigned char *) key, ht->size);
		return (shash_chain_get(ht->array[index], key));
	}
	return (0);
}

/**
 * shash_table_print - print the elements in a hash table
 * @ht: a pointer to the hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	const shash_node_t *shead = NULL;

	if (ht)
	{
		putchar('{');
		shead = ht->shead;
		if (shead)
		{
			for (;;)
			{
				if (shead->value)
					printf("'%s': '%s'",
						shead->key, shead->value);
				else
					printf("'%s': %s",
						shead->key, shead->value);

				shead = shead->snext;

				if (shead)
					fputs(", ", stdout);
				else
					break;
			}
		}
		puts("}");
	}
}

/**
 * shash_table_print_rev - print the elements in a hash table (reverse)
 * @ht: a pointer to the hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	const shash_node_t *stail = NULL;

	if (ht)
	{
		putchar('{');
		stail = ht->stail;
		if (stail)
		{
			for (;;)
			{
				if (stail->value)
					printf("'%s': '%s'",
						stail->key, stail->value);
				else
					printf("'%s': %s",
						stail->key, stail->value);

				stail = stail->sprev;

				if (stail)
					fputs(", ", stdout);
				else
					break;
			}
		}
		puts("}");
	}
}

/**
 * shash_list_delete - delete a doubly-linked list
 * @shead: a pointer to the head of the doubly-linked list
 */
void shash_list_delete(shash_node_t *shead)
{
	if (shead)
	{
		shash_list_delete(shead->snext);
		free(shead->key);
		free(shead->value);
		free(shead);
	}
}

/**
 * shash_table_delete - delete a hash table
 * @ht: a pointer to the hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	if (ht)
	{
		shash_list_delete(ht->shead);
		free(ht->array);
		free(ht);
	}
}
