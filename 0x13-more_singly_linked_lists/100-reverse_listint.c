#include "lists.h"

/**
 * _reverse_listint - reverse a linked list (helper function)
 * @current: a pointer to the first node
 *
 * Return: a pointer to the first node of the reversed list
 */
listint_t *_reverse_listint(listint_t *current)
{
	listint_t *tail;

	if (!current)
		return (NULL);

	tail = _reverse_listint(current->next);

	if (!tail)
		return (current);

	(current)->next->next = current;
	(current)->next = NULL;

	return (tail);
}

/**
 * reverse_listint - reverse a linked list
 * @head: a pointer to a pointer to the first node
 *
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	if (!head)
		return (NULL);

	*head = _reverse_listint(*head);
	return (*head);
}
