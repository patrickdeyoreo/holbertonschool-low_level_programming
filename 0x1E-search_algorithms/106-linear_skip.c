#include "search_algos.h"
#include <math.h>

#define VALUE_CHECKED(idx, item) \
	printf("Value checked at index [%lu] = [%d]\n", (idx), (item))

#define VALUE_BOUNDED(low, high) \
	printf("Value found between indexes [%lu] and [%lu]\n", (low), (high))

/**
 * linear_skip - search for a value in a sorted list of integers
 * @list: list of values
 * @value: value to locate
 *
 * Return: If value is not present in list or list is NULL, return -1.
 * Otherwise, returh the first node where value is located.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *head = list;

	if (list)
	{
		while (list->express && value > list->n)
		{
			head = list;
			list = list->express;
			VALUE_CHECKED(list->index, list->n);
		}
		if (value > list->n)
		{
			head = list;
		}
		while (list->next && value > list->n)
		{
			list = list->next;
			VALUE_CHECKED(list->index, list->n);
		}
		VALUE_BOUNDED(head->index, list->index);
		list = list->next;
		while (head != list)
		{
			VALUE_CHECKED(head->index, head->n);
			if (head->n == value)
				return (head);
			head = head->next;
		}
	}
	return (NULL);
}
