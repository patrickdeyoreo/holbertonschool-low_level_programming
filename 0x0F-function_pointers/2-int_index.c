#include "function_pointers.h"

/**
 * int_index - search for an integer
 * @array: the array to search
 * @size: the number of elements in the array
 * @cmp: the function to use to compare values (returns non-zero upon a match)
 *
 * Return: If no match is found or size is less than 1, or if array is NULL or
 * cmp is NULL, return -1. Otherwise return the index of the first match.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (cmp && array)
	{
		for (i = 0; i < size; ++i)
		{
			if (cmp(array[i]))
				return (i);
		}
	}

	return (-1);
}
