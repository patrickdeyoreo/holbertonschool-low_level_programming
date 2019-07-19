#include "holberton.h"

/**
 * array_range - create an array of integers
 *
 * Return: If memory allocation fails or min is greater than max, return NULL.
 * Otherwise, return the newly created array.
 */
int *array_range(int min, int max)
{
	int *range;
	unsigned int width;

	if (max < min)
		return (NULL);

	width = max - min;

	range = malloc(sizeof (int) * width + 1);
	if (!range)
		return (NULL);

	do {
		*range++ = min;
	} while (++min < max);

	return (range - width);
}
