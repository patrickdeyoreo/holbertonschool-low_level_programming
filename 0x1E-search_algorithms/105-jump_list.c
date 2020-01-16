#include "search_algos.h"
#include <math.h>

#define PRINT_CHECKED(idx, item) \
	printf("Value checked at index [%lu] = [%d]\n", (idx), (item))

#define PRINT_BOUNDED(low, high) \
	printf("Value found between indexes [%lu] and [%lu]\n", (low), (high))

/**
 * jump_list - search for a value in a sorted list of integers
 * @list: list of values
 * @size: number of values
 * @value: value to locate
 *
 * Return: If value is not present in list or list is NULL, return -1.
 * Otherwise, returh the first node where value is located.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	listint_t *tail = list;
	size_t jump = sqrt(size);

	if (list && size)
	{
		while (tail->next && value > tail->n)
		{
			list = tail;
			size = jump;
			while (size-- && tail->next)
				tail = tail->next;
			PRINT_CHECKED(tail->index, tail->n);
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
