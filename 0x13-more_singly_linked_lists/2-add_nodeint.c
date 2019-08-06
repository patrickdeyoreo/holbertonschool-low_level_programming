#include "lists.h"

/**
 * add_nodeint - add an element at the beginning of a linked list
 * @head: a pointer to a pointer to the first node
 * @n: the element to add
 *
 * Return: If memory allocation fails or head is NULL, return NULL.
 * Otherwise, return the address of the new node.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}
