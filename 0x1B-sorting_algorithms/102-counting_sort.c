#include "sort.h"

/**
 * get_max - get the maximum value in an array
 * @array: the array from which to get the max
 * @size: the size of the array
 *
 * Return: the maximum value
 */
int get_max(int *array, size_t size)
{
	int max = 0;

	while (size--)
	{
		if (max < array[size])
			max = array[size];
	}
	return (max);
}

/**
 * count_unique - count unique of unique values
 * @dest: the array to store the result
 * @src: the array from which to count values
 * @size: the size of the src array
 */
void count_unique(int *dest, int *src, size_t size)
{
	while (size--)
		dest[*src++] += 1;
}

/**
 * build_values - construct a map of values to sorted indices
 * @unique: the array in which to store the map
 * @size: the size of the unique array
 */
void build_values(int *unique, int size)
{
	int i = 0;

	while (++i < size)
		unique[i] += unique[i - 1];
}

/**
 * build_sorted - construct a map of values to indices
 * @array: the original array to sort
 * @sorted: the array in which to store the result
 * @unique: the map of values to sorted indices
 * @size: the size of the array to sort
 */
void build_sorted(int *array, int *sorted, int *unique, size_t size)
{
	while (size--)
		sorted[--(unique[array[size]])] = array[size];
}

/**
 * counting_sort - execute the (peculiar) counting sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max, *unique, *sorted;

	if (!array || size < 2)
		return;

	sorted = malloc(sizeof(*sorted) * size);
	if (!sorted)
		return;

	max = get_max(array, size);
	unique = calloc(max + 1, sizeof(*unique));
	if (!unique)
		return;

	count_unique(unique, array, size);
	build_values(unique, max + 1);
	print_array(unique, max + 1);
	build_sorted(array, sorted, unique, size);
	while (size--)
		array[size] = sorted[size];

	free(sorted);
	free(unique);
}
