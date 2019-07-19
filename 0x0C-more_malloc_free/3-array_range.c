#include "holberton.h"

/**
 * array_range - create an array of integers containing a range of values
 * @min: the lower bound (included)
 * @max: the upper bound (included)
 *
 * Return: If memory allocation fails or max is less than max, return NULL.
 * Otherwise, return the newly created array.
 */
int *array_range(int min, int max)
{
	int *range;
	unsigned int width;

	if (max < min)
		return (NULL);

	width = max - min;

	range = malloc(sizeof(int) * (width + 1));
	if (!range)
		return (NULL);

	do {
		*range++ = min++;
	} while (min <= max);

	return (range - width - 1);
}
