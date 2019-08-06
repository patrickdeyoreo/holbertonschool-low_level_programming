#include "lists.h"

/**
 * add_nodeint_end - add an element at the end of a linked list
 * @head: a pointer to a pointer to the first node
 * @n: the element to add
 *
 * Return: If memory allocation fails or head is NULL, return NULL.
 * Otherwise, return the address of the new node.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;

	if (!head)
		return (NULL);

	if (*head)
		return (add_nodeint_end(&(*head)->next, n));

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}
