#include "sort.h"

/**
 * cocktail_forward - do a forward pass
 * @list: a double pointer to the head of the list
 * @head: the starting point
 */
void cocktail_forward(listint_t **list, listint_t *head)
{
	static int flag;
	listint_t *curr;
	listint_t *temp;

	flag = 0;
	while (curr = head, head = head->next)
	{
		if (curr->n > head->n)
		{
			flag = 1;
			temp = head->next;
			head->next = curr;
			curr->next = temp;
			if (temp)
				temp->prev = curr;
			temp = curr->prev;
			curr->prev = head;
			head->prev = temp;
			if (temp)
				temp->next = head;
			if (!head->prev)
				*list = head;
			print_list(*list);
			head = curr;
		}
	}
	if (flag)
		cocktail_backward(list, curr);
}

/**
 * cocktail_backward - do a backward pass
 * @list: a double pointer to the head of the list
 * @tail: the starting point
 */
void cocktail_backward(listint_t **list, listint_t *tail)
{
	static int flag;
	listint_t *curr;
	listint_t *temp;

	flag = 0;
	while (curr = tail, tail = tail->prev)
	{
		if (tail->n > curr->n)
		{
			flag = 1;
			temp = tail->prev;
			tail->prev = curr;
			curr->prev = temp;
			if (temp)
				temp->next = curr;
			temp = curr->next;
			curr->next = tail;
			tail->next = temp;
			if (temp)
				temp->prev = tail;
			if (!curr->prev)
				*list = curr;
			print_list(*list);
			tail = curr;
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
	if (list && *list)
		cocktail_forward(list, *list);
}
