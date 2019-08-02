#include "lists.h"

/**
 * free_list - a linked list
 * @head: the first list node
 */
void free_list(list_t *head)
{
	if (head)
		free_list(head->next);
	free(head);
	head = NULL;
}
