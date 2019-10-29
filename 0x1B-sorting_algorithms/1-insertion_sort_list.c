#include "sort.h"

/**
 * insertion_sort_list - Perform the insertion sort alogorithm
 * @list: a double pointer to the head of a list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr;
	listint_t *next;
	listint_t *prev;
	listint_t *temp;

	if (list && *list)
	{
		next = (*list)->next;
		while ((curr = next))
		{
			next = curr->next;
			prev = curr->prev;
			while (prev && prev->n > curr->n)
			{
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

				prev = curr->prev;
				if (prev)
					print_list(*list);
				else
					print_list((*list = curr));
			}
		}
	}
}
