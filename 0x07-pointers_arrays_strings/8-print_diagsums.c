#include "holberton.h"
#include <math.h>
#include <stdio.h>

/**
 * print_diagsums - print the diagonal sums of a square matrix
 * @a: pointer to the element at (row 0, column 0)
 * @size: the size of one dimension of the matrix
 *
 * Return: void
 */
void print_diagsums(int *a, int size)
{
	int row, *pos;
	int sum1 = 0;
	int sum2 = 0;

	for (pos = a, row = 0; row < size; ++row, pos += size + 1)
		sum1 += *pos;

	for (pos = a + size - 1, row = 0; row < size; ++row, pos += size - 1)
		sum2 += *pos;

	printf("%d, %d\n", sum1, sum2);
}
