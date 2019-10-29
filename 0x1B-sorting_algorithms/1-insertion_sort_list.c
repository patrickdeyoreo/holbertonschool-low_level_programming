#include "sort.h"

/**
 * insertion_swap_nodes - Swap two nodes
 * @a: a double pointer to a node
 * @b: a double pointer to a node
 */
void swap(listint_t *a, listint_t *b)
{
	listint_t *temp;

	temp = a->next;
	a->next = b->next;
	if (a->next)
		a->next->prev = a;
	b->next = temp;
	if (b->next)
		b->next->prev = b;

	temp = a->prev;
	a->prev = b->prev;
	if (a->prev)
		a->prev->next = a;
	b->prev = temp;
	if (b->prev)
		b->prev->next = b;
}

/**
 * insertion_sort_list - Perform the insertion sort alogorithm
 * @list: a double pointer to the head of a list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr = NULL;
	listint_t *prev = NULL;
	listint_t *temp = NULL;

	if (!(list && *list))
		return;

	prev = (*list);
	curr = (*list)->next;

	while (curr)
	{
		temp = curr;
		curr = curr->next;
		while (prev && temp->n < prev->n)
		{
			print_list(*list);
			swap(temp, prev);
			prev = temp->prev;
		}
		if (!prev)
			*list = temp;
		if (curr)
			prev = curr->prev;
	}
}
