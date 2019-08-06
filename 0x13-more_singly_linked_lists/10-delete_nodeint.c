#include "lists.h"

/**
 * delete_nodeint_at_index - delete the element at the given index of a list
 * @head: a pointer to a pointer to the first node
 * @index: the index of the element to delete
 *
 * Return: 1 upon success, -1 upon failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *next;

	if (!head)
		return (-1);
	if (index && *head)
		return (delete_nodeint_at_index(&(*head)->next, index - 1));
	if (index || !(*head))
		return (-1);

	next = (*head)->next;
	free(*head);
	*head = next;

	return (1);
}
