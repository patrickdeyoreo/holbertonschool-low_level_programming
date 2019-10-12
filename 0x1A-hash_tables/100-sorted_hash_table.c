#include "hash_tables.h"
#include <string.h>

/**
 * shash_table_create - create a new hash table
 * @size: the size of the new hash table
 *
 * Return: a pointer to a newly created hash table
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
 * _shash_table_set - set an element in a hash table (helper)
 * @head: pointer to a linked list
 * @key: the key of the element
 * @new_value: the element
 *
 * Return: 1 upon success, otherwise 0
 */
int _shash_table_set(shash_node_t *head, const char *key, char *new_value)
{
	if (head)
	{
		if (!strcmp(key, head->key))
		{
			free(head->value);
			head->value = new_value;
			return (1);
		}
		return (_shash_table_set(head->next, key, new_value));
	}
	return (0);
}

/**
 * _shash_node_insert - insert an element in a doubly-linked list
 * @ht: pointer to a hash table
 * @snode: pointer to a node to insert
 */
void _shash_node_insert(shash_table_t *ht, shash_node_t *snode)
{
	shash_node_t *shead = ht->shead, *sprev = NULL;

	if (!shead)
	{
		ht->shead = snode;
		ht->stail = snode;
		snode->sprev = NULL;
		snode->snext = NULL;
		return;
	}

	if (strcmp(shead->key, snode->key) > 0)
	{
		ht->shead = snode;
		snode->sprev = NULL;
		snode->snext = shead;
		shead->sprev = snode;
		return;
	}

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

/**
 * shash_table_set - set an element in a hash table
 * @ht: pointer to a hash table
 * @key: the key of the element
 * @value: the element
 *
 * Return: 1 upon success, otherwise 0
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node = NULL;
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
	if (_shash_table_set(ht->array[idx], key, new_value))
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
	new_node->next = ht->array[idx];
	ht->array[idx] = new_node;
	_shash_node_insert(ht, new_node);
	return (1);
}

/**
 * _shash_table_get - get an element from a hash table (helper)
 * @head: pointer to a linked list
 * @key: the key of the element
 *
 * Return: a pointer to the element, or NULL if the key was not found
 */
char *_shash_table_get(const shash_node_t *head, const char *key)
{
	if (head)
	{
		if (strcmp(key, head->key))
			return (_shash_table_get(head->next, key));
		return (head->value);
	}
	return (NULL);
}

/**
 * shash_table_get - get an element from a hash table
 * @ht: pointer to a hash table
 * @key: the key of the desired element
 *
 * Return: a pointer to the element, or NULL if the key was not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	if (!(ht && key && *key))
		return (0);

	return (_shash_table_get(
			ht->array[key_index((const unsigned char *) key, ht->size)],
			key
			));
}

/**
 * shash_table_print - print all entries in a hash table
 * @ht: pointer to a hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *head = NULL;

	if (!ht)
		return;

	putchar('{');
	head = ht->shead;
	while (head)
	{
		printf("'%s': ", head->key);

		if (head->value)
			printf("'%s'", head->value);
		else
			printf("%s", head->value);

		head = head->snext;
		if (head)
			printf(", ");
	}
	puts("}");
}

/**
 * shash_table_print_rev - print all entries in a hash table
 * @ht: pointer to a hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tail = NULL;

	if (!ht)
		return;

	putchar('{');
	tail = ht->stail;
	while (tail)
	{
		printf("'%s': ", tail->key);

		if (tail->value)
			printf("'%s'", tail->value);
		else
			printf("%s", tail->value);

		tail = tail->sprev;
		if (tail)
			printf(", ");
	}
	puts("}");
}

/**
 * _shash_table_delete - delete a hash table
 * @head: pointer to a linked list
 */
void _shash_table_delete(shash_node_t *head)
{
	if (head)
	{
		_shash_table_delete(head->next);
		free(head->key);
		free(head->value);
		free(head);
	}
}

/**
 * shash_table_delete - delete a hash table
 * @ht: a pointer to a hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t **array = NULL;
	unsigned int index = 0, size = 0;

	if (!ht)
		return;

	for (array = ht->array, size = ht->size; index < size; ++index)
		_shash_table_delete(array[index]);

	free(ht->array);
	free(ht);
}
