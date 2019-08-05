#include "lists.h"

/**
 * free_listint - free a linked list
 * @head: a pointer to the first node
 */
void free_listint(listint_t *head)
{
	if (head)
	{
		free_listint(head->next);
		free(head);
	}
}
