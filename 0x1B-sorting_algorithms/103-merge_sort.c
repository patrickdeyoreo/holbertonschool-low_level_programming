#include "sort.h"
#include <stdio.h>

void intcpy(int *dest, const int *src, size_t size)
{
	while (size--)
		*dest++ = *src++;
}

void conquer(int *dest, const int *left, const int *right, size_t size)
{
	const int *lstop = left + size / 2;
	const int *rstop = right + (size_t) (size + 0.5) / 2;

	printf("[Left]: ");
	print_array(dest, lstop - left);
	printf("[Right]: ");
	print_array(dest, rstop - right);

	while (left < lstop && right < rstop)
		*dest = (*left < *right) ? *left++ : *right++;
}

/**
 * divide - Merge sort recursion
 * @dest: array to store results
 * @src: array to be sorted
 * @size: size of the array
 */
void divide(int *dest, const int *src, size_t size)
{
	if (size > 1)
	{
		divide(dest, src, size / 2);
		divide(dest + size / 2, src + size / 2, size / 2);

		conquer(dest, src, src + size / 2, size);

		printf("[Done]: ");
		print_array(dest, size);
	}
}

/**
 * merge_sort - Perform a merge sort
 * @array: the array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *aux = malloc(sizeof(*aux) * size);

	if (aux)
	{
		intcpy(aux, array, size);
		divide(aux, array, size);
		intcpy(array, aux, size);
		free(aux);
	}
}
