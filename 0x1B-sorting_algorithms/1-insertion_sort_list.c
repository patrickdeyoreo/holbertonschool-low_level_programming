#include "sort.h"

/**
 * insertion_sort_list - Perform the insertion sort alogorithm
 * @list: a double pointer to the head of a list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL;
	listint_t *next = NULL;
	listint_t *prev = NULL;
	listint_t *temp = NULL;

	if (list && *list)
	{
		next = (*list)->next;
		while ((curr = next))
		{
			next = curr->next;
			while ((prev = curr->prev) && prev->n > curr->n)
			{
				print_list(*list);
				temp = prev->prev;
				prev->prev = curr;
				curr->prev = temp;
				if (temp)
					temp->next = curr;
				temp = curr->next;
				curr->next = prev;
				prev->next = temp;
				if (temp)
					temp->prev = prev;
			}
			if (!prev)
				*list = curr;
		}
	}
}
