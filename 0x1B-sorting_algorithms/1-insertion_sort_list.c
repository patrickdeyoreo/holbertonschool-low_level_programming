#include "sort.h"

/**
 * insertion_sort_list -
 * @list: a double pointer the head of a list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL;
	listint_t *prev = NULL;
	listint_t *temp = NULL;


	if (!(list && *list))
		return;

	curr = (*list)->next;
	while (curr)
	{
		if (curr->n < curr->prev->n)
		{
			if (curr->next)
				curr->next->prev = curr->prev;
			curr->prev->next = curr->next;
			temp = curr;
			prev = curr->prev;
			curr = curr->next;

			while (prev && temp->n < prev->n)
				prev = prev->prev;

			if (prev)
			{
				temp->next = prev->next;
				temp->next->prev = temp;
				temp->prev = prev;
				prev->next = temp;
			}
			else
			{
				temp->next = *list;
				temp->prev = NULL;
				(*list)->prev = temp;
				*list = temp;
			}
			print_list(*list);
		}
		else
		{
			curr = curr->next;
		}
	}
}
