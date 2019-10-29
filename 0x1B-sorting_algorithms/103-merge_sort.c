#include "sort.h"
#include <stdio.h>

/**
 * intcopy - copy an array of integers
 * @dest: the destination array
 * @src: the source array
 * @size: the size of the array
 */
void intcopy(int *dest, const int *src, size_t size)
{
	while (size--)
		*dest++ = *src++;
}

/**
 * conquer - merge two sub-arrays
 * @array: the array to be sorted
 * @aux: the array to hold results
 * @lsize: the size of the left sub-array
 * @rsize: the size of the right sub-array
 */
void conquer(int *array, int *aux, size_t lsize, size_t rsize)
{
	int *lstart = array, *lstop = lstart + lsize;
	int *rstart = lstop, *rstop = rstart + rsize;

	printf("Merging...\n");

	printf("[left]: ");
	print_array(lstart, lsize);

	printf("[right]: ");
	print_array(rstart, rsize);

	while (lstart < lstop && rstart < rstop)
		*aux++ = (*lstart <= *rstart) ? *lstart++ : *rstart++;

	while (lstart < lstop)
		*aux++ = *lstart++;

	while (rstart < rstop)
		*aux++ = *rstart++;
}

/**
 * divide - divide, sort and merge
 * @array: the array to be sorted
 * @aux: the array to hold results
 * @size: the size of the array
 */
void divide(int *array, int *aux, size_t size)
{
	size_t lsize = size / 2;
	size_t rsize = size / 2 + size % 2;

	if (size > 1)
	{
		divide(array, aux, lsize);
		divide(array + lsize, aux + lsize, rsize);

		conquer(array, aux, lsize, rsize);
		intcopy(array, aux, size);

		printf("[Done]: ");
		print_array(array, size);
	}
}

/**
 * merge_sort - Perform a merge sort
 * @array: the array to be sorted
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *aux = malloc(sizeof(*aux) * size);

	if (aux)
	{
		divide(array, aux, size);
		free(aux);
	}
}
