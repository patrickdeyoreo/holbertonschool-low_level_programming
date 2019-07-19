#include "holberton.h"

/**
 * array_range - create an array of integers containing a range of values
 * @min: the lower bound (included)
 * @max: the upper bound (included)
 *
 * Return: If memory allocation fails or min is greater than max, return NULL.
 * Otherwise, return the newly created array.
 */
int *array_range(int min, int max)
{
	int *range, *pos;
	unsigned long width;

	if (max < min)
		return (NULL);

	width = (long) max - (long) min;

	range = malloc(sizeof(int) * width + 1);
	if (!range)
		return (NULL);

	for (pos = range; min <= max; ++pos, ++min)
	{
		*pos = min;
	}

	return (range);
}
