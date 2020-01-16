#include "search_algos.h"

#define PRINT_CHECKED(idx, item) \
	printf("Value checked array[%lu] = [%d]\n", (idx), (item))

#define PRINT_BOUNDED(low, high) \
	printf("Value found between indexes [%lu] and [%lu]\n", (low), (high))

/**
 * jump_search - search for a value in a sorted array of integers
 * @array: the array of values
 * @size: the number of values
 * @value: the value to locate
 *
 * Return: If value is not present in array or array is NULL, return -1.
 * Otherwise, returh the first index where value is located.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i = 0, j = 0;

	if (array && size)
	{
		while (j < size && array[j] < value)
		{
			PRINT_CHECKED(j, array[j]);
			i = j, j += 3;
		}
		PRINT_BOUNDED(i, j);
		if (size <= j)
			j = size - 1;
		while (i <= j)
		{
			PRINT_CHECKED(i, array[i]);
			if (array[i] == value)
				return (i);
			++i;
		}
	}
	return (-1);
}
