#include "search_algos.h"

/**
 * linear_search - search for a value in an array of integers
 * @array: array of values to search
 * @size: size of the array
 * @value: value to find
 *
 * Return: If value is not present in array or array is NULL, return -1.
 * Otherwise, returh the first index where value is located.
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array)
	{
		for (i = 0; i < size; ++i)
		{
			printf("Value checked array[%lu] = [%d]\n", i, array[i]);
			if (array[i] == value)
				return (i);
		}
	}
	return (-1);
}
