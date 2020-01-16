#include "search_algos.h"

#define JUMPSIZE 3

#define VALUE_CHECKED(array, index) \
	printf("Value checked array[%lu] = [%d]\n", (index), (array)[index])

#define VALUE_BOUNDED(lower, upper) \
	printf("Value found between indexes [%lu] and [%lu]\n", (lower), (upper))

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
	size_t i;

	if (array && size)
	{
		for (i = 0; i < size && array[i] < value; i += JUMPSIZE)
		{
			VALUE_CHECKED(array, i);
		}
		VALUE_BOUNDED(i - JUMPSIZE, i);
		if (size > i)
			size = i + 1;
		for (i -= JUMPSIZE; i < size; ++i)
		{
			VALUE_CHECKED(array, i);
			if (array[i] == value)
				return (i);
		}
	}
	return (-1);
}
