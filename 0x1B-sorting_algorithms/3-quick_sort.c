#include "sort.h"
#include <stdio.h>

/**
 * conquer - sort the paritions
 * @array: the array to sort
 * @size: the size of the array
 * @lower: the lower bound (inclusive)
 * @upper: the upper bound (inclusive)
 *
 * Return: the index of the new partition
 */
size_t conquer(int *array, size_t size, ssize_t lower, ssize_t upper)
{
	ssize_t index = lower;

	while (index < upper)
	{
		if (array[index] < array[upper])
		{
			if (lower != index)
			{
				array[lower] ^= array[index];
				array[index] ^= array[lower];
				array[lower] ^= array[index];
				print_array(array, size);
			}
			lower += 1;
		}
		index += 1;
	}
	if (array[lower] != array[upper])
	{
		array[lower] ^= array[upper];
		array[upper] ^= array[lower];
		array[lower] ^= array[upper];
		print_array(array, size);
	}
	return (lower);
}

/**
 * divide - partition the array
 * @array: the array to sort
 * @size: the size of the array
 * @lower: the lower bound (inclusive)
 * @upper: the upper bound (inclusive)
 */
void divide(int *array, size_t size, ssize_t lower, ssize_t upper)
{
	ssize_t partition;

	if (lower < upper)
	{
		partition = conquer(array, size, lower, upper);
		divide(array, size, lower, partition - 1);
		divide(array, size, partition + 1, upper);
	}
}

/**
 * quick_sort - perform the quick sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array && size)
		divide(array, size, 0, size - 1);
}
