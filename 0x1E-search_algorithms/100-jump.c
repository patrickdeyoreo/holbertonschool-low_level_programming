#include "search_algos.h"

#define JUMP 3

/**
 * jump_search - search for a value in a sorted array of integers
 * @array: array of values to search
 * @size: size of the array
 * @value: value to find
 *
 * Return: If value is not present in array or array is NULL, return -1.
 * Otherwise, returh the first index where value is located.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i;

	if (array)
	{
		for (i = 0; i < size && array[i] < value; i += JUMP)
		{
			printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		}
		printf("Value found between indexes [%lu] and [%lu]\n", i - JUMP, i);

		if (size > i)
		{
			size = i + 1;
		}
		for (i -= JUMP; i < size; ++i)
		{
			printf("Value checked array[%lu] = [%d]\n", i, array[i]);
			if (array[i] == value)
				return (i);
		}
	}
	return (-1);
}
