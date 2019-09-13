#include "lists.h"

/**
 * add_dnodeint_end - add a node at the end of a doubly-linked list
 * @head: pointer to a pointer to the beginning of a doubly-linked list
 * @n: the data to add
 *
 * Return: If memory allocation fails or head is NULL, return NULL.
 * Otherwise, return a pointer to the new node.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *tail, *new = NULL;

	if (head)
	{
		new = malloc(sizeof(*new));
		if (new)
		{
			new->n = n;
			new->next = NULL;

			tail = *head;

			if (tail)
			{
				while (tail->next)
					tail = tail->next;

				new->prev = tail;
				tail->next = new;
			}
			else
			{
				new->prev = NULL;
				*head = new;
			}
		}
	}
	return (new);
}
