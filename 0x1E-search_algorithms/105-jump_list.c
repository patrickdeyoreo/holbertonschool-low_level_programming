#include "search_algos.h"
#include <math.h>

#define VALUE_CHECKED(idx, item) \
	printf("Value checked array[%lu] = [%d]\n", (idx), (item))

#define VALUE_BOUNDED(low, high) \
	printf("Value found between indexes [%lu] and [%lu]\n", (low), (high))

/**
 * jump_list - search for a value in a sorted list of integers
 * @list: list of values
 * @size: number of values
 * @value: value to locate
 *
 * Return: If value is not present in array or array is NULL, return -1.
 * Otherwise, returh the first index where value is located.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	listint_t *head = list;
	size_t rep = 0;

	if (list && size)
	{
		while (list->next && value > list->n)
		{
			head = list;
			for (rep = sqrt(size); list->next && rep; --rep)
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
