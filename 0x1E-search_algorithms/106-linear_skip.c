#include "search_algos.h"
#include <math.h>

#define PRINT_CHECKED(idx, item) \
	printf("Value checked at index [%lu] = [%d]\n", (idx), (item))

#define PRINT_BOUNDED(low, high) \
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
	skiplist_t *tail = list;

	if (list)
	{
		while (tail->express && value > tail->n)
		{
			list = tail;
			tail = tail->express;
			PRINT_CHECKED(tail->index, tail->n);
		}
		if (value > tail->n)
		{
			list = tail;
			while (tail->next)
				tail = tail->next;
		}
		PRINT_BOUNDED(list->index, tail->index);
		tail = tail->next;
		while (list != tail)
		{
			PRINT_CHECKED(list->index, list->n);
			if (list->n == value)
				return (list);
			list = list->next;
		}
	}
	return (NULL);
}
