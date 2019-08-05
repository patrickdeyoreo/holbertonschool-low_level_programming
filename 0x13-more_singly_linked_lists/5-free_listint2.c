#include "lists.h"

/**
 * free_listint2 - free a linked list and set the head to NULL
 * @head_ptr: a pointer to a pointer the first node
 */
void free_listint2(listint_t **head_ptr)
{
	if (head_ptr && *head_ptr)
	{
		free_listint2(&(*head_ptr)->next);
		*head_ptr = NULL;
	}
}
