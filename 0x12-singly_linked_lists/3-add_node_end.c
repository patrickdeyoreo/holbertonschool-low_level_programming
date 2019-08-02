#include "lists.h"

/**
 * _strlen - calculate the length of a string
 * @s: the string to calculate the length of
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	if (s)
	{
		while (*(s + len))
			++len;
	}

	return (len);
}

/**
 * _strdup - create a new array containing a copy of the given string
 * @str: a pointer to the string to copy
 *
 * Return: If str is NULL or if memory allocation fails, return NULL.
 * Otherwise a return a pointer to the new copy
 */
char *_strdup(const char *str)
{
	char *dup;
	unsigned int size = 0;

	if (!str)
		return (NULL);

	while (str[size++])
		;

	dup = malloc(sizeof(char) * size);
	if (!dup)
		return (NULL);

	while (size--)
		dup[size] = str[size];

	return (dup);
}

/**
 * add_node_end - add a string at the end of the list
 * @head: a pointer to the address of the first list node
 * @str: the string to add to the list
 *
 * Return: If memory allocation fails, return NULL. Otherwise, return the
 * address of the new no
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node;

	if (!head)
		return (NULL);

	if (*head)
		return (add_node_end(&(*head)->next, str));

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);

	new_node->str = _strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}
	new_node->len = (_strlen(new_node->str));

	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
