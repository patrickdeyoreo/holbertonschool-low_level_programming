#include "sort.h"

/**
 * cocktail_forward - do a forward pass
 * @list: a double pointer to the head of the list
 */
void cocktail_forward(listint_t **list, listint_t *next)
{
	listint_t *curr, *temp;
	int flag = 0;

	while ((curr = next) && (next = curr->next))
	{
		if (curr->n > next->n)
		{
			temp = next->next;
			next->next = curr;
			curr->next = temp;
			if (temp)
				temp->prev = curr;
			temp = curr->prev;
			curr->prev = next;
			next->prev = temp;
			if (temp)
				temp->next = next;
			if (next->prev)
				print_list(*list);
			else
				print_list((*list = next));
			flag = 1;
			next = curr;
		}
	}
	if (flag)
		cocktail_backward(list, curr);
}

/**
 * cocktail_backward - do a forward pass
 * @list: a double pointer to the head of the list
 * @prev: the starting point
 */
void cocktail_backward(listint_t **list, listint_t *prev)
{
	listint_t *curr, *temp;
	int flag = 0;

	while ((curr = prev) && (prev = curr->prev))
	{
		if (prev->n > curr->n)
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
			if (curr->prev)
				print_list(*list);
			else
				print_list((*list = curr));
			flag = 1;
			prev = curr;
		}
	}
	if (flag)
		cocktail_forward(list, curr);
}

/**
 * cocktail_sort_list - Perform the cocktail sort algorithm
 * @list: a double pointer to the head of a list
 */
void cocktail_sort_list(listint_t **list)
{
	if (list)
		cocktail_forward(list, *list);
}
