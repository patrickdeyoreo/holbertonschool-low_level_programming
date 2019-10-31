#include "sort.h"

/**
 * swap - swap nodes
 * @lhs: a pointer to the node before rhs
 * @rhs: a pointer to the node after lhs
 */
void swap(listint_t *lhs, listint_t *rhs)
{
	if (rhs->next)
		rhs->next->prev = lhs;
	if (lhs->prev)
		lhs->prev->next = rhs;
	lhs->next = rhs->next;
	rhs->next = lhs;
	rhs->prev = lhs->prev;
	lhs->prev = rhs;
}

/**
 * insertion_sort_list - Perform the insertion sort alogorithm
 * @list: a double pointer to the head of a list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr;
	listint_t *next;
	listint_t *prev;

	if (list && *list)
	{
		next = (*list)->next;
		while ((curr = next))
		{
			next = curr->next;
			prev = curr->prev;
			while (prev && prev->n > curr->n)
			{
				swap(prev, curr);
				prev = curr->prev;
				if (!prev)
					*list = curr;
				print_list(*list);
			}
		}
	}
}
