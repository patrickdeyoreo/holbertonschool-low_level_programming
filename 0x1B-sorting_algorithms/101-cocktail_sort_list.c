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
 * cocktail_forward - do a forward pass
 * @list: a double pointer to the head of the list
 * @head: the starting point
 */
void cocktail_forward(listint_t **list, listint_t *head)
{
	static listint_t *stop;
	static listint_t *curr;
	static int flag;

	flag = 0;
	while (head != stop && (curr = head, head = head->next))
	{
		if (curr->n > head->n)
		{
			flag = 1;
			swap(curr, head);
			if (!head->prev)
				*list = head;
			print_list(*list);
			head = curr;
		}
	}
	if (flag)
	{
		stop = curr;
		cocktail_backward(list, curr);
	}
}

/**
 * cocktail_backward - do a backward pass
 * @list: a double pointer to the head of the list
 * @tail: the starting point
 */
void cocktail_backward(listint_t **list, listint_t *tail)
{
	static listint_t *stop;
	static listint_t *curr;
	static int flag;

	flag = 0;
	while (tail != stop && (curr = tail, tail = tail->prev))
	{
		if (tail->n > curr->n)
		{
			flag = 1;
			swap(tail, curr);
			if (!curr->prev)
				*list = curr;
			print_list(*list);
			tail = curr;
		}
	}
	if (flag)
	{
		stop = curr;
		cocktail_forward(list, curr);
	}
}

/**
 * cocktail_sort_list - Perform the cocktail sort algorithm
 * @list: a double pointer to the head of a list
 */
void cocktail_sort_list(listint_t **list)
{
	if (list && *list)
		cocktail_forward(list, *list);
}
