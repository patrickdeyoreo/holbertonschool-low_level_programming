#include "search_algos.h"

/**
 * print_array - print the values in an array
 * @array: array of values to print
 * @lo: the smallest index to print
 * @hi: the greatest index to print
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
 * @array: array of values to search
 * @size: size of the array
 * @value: value to find
 *
 * Return: If value is not present in array or array is NULL, return -1.
 * Otherwise, returh the first index where value is located.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t lo, hi;

	if (array)
	{
		lo = 0;
		hi = size - 1;
		while (lo < hi)
		{
			print_array(array, lo, hi);
			if (array[(hi - lo) / 2] < value)
				lo += (hi - lo) / 2 + 1;
			if (array[(hi - lo) / 2] > value)
				hi -= (hi - lo) / 2 + 2;
			if (array[(hi - lo) / 2] == value)
				return ((hi - lo) / 2);
		}
		print_array(array, lo, hi);
		if (lo == hi)
			return (array[lo] == value ? (int) lo : -1);

	}
	return (-1);
}
