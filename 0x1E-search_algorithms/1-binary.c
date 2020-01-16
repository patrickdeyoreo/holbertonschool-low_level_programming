#include "search_algos.h"

/**
 * print_array - print the values in an array
 * @array: the array of values
 * @lo: the smallest index
 * @hi: the greatest index
 */
static void print_array(int *array, size_t lo, size_t hi)
{
	printf("Searching in array: ");
	while (lo <= hi)
	{
		if (lo < hi)
			printf("%d, ", array[lo++]);
		else
			printf("%d\n", array[lo++]);
	}
}

/**
 * binary_search - search for a value in a sorted array of integers
 * @array: the array of values
 * @size: the number of values
 * @value: the value to locate
 *
 * Return: If value is not present in array or array is NULL, return -1.
 * Otherwise, returh the first index where value is located.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t lo = 0, hi = size - 1, mid = 0;

	if (array && size)
	{
		while (1)
		{
			mid = (lo + hi) / 2;

			print_array(array, lo, hi);

			if (lo == hi)
				return (array[lo] == value ? (int) lo : -1);

			if (array[mid] == value)
				return (mid);

			if (array[mid] < value)
				lo = mid + 1;
			else
				hi = mid - 1;
		}

	}
	return (-1);
}
