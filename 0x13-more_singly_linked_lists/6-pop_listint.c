#include "lists.h"

/**
 * pop_listint - get the first element of a linked list and remove it
 * @head_ptr: a pointer to a pointer to the first node
 *
 * Return: the first list element, or 0 if the list is empty
 */
int pop_listint(listint_t **head_ptr)
{
	int data;
	listint_t *old_head;

	if (!(head_ptr && *head_ptr))
		return (0);

	data = (*head_ptr)->n;

	old_head = *head_ptr;
	*head_ptr = old_head->next;
	free(old_head);

	return (data);
}
