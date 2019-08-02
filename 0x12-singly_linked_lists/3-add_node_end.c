#include "lists.h"

/**
 * _strlen - calculate the length of a string
 * @str: the string to calculate the length of
 *
 * Return: the length of the string
 */
size_t _strlen(const char *str)
{
	const char *pos = str;

	if (str)
	{
		while (*pos)
			++pos;
	}
	return (pos - str);
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
	char *dup = NULL;
	size_t size = 0;

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
	list_t *new = NULL;

	if (!head)
		return (NULL);

	if (*head)
		return (add_node_end(&(*head)->next, str));

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);


	new->str = _strdup(str);
	new->len = (_strlen(new->str));
	new->next = *head;

	*head = new;

	return (new);
}
