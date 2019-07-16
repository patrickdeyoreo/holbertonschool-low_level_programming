#include "holberton.h"

/**
 * alloc_grid - create a 2-dimensional array with each element set to 0
 * @width: desired number of columns
 * @height: desired number of rows
 *
 * Return: NULL if memory allocation fails or any argument is less than 1,
 * otherwise return a pointer to the first element of the array.
 */
int **alloc_grid(int width, int height)
{
	int **matrix, column;

	if (width < 1 || height < 1)
		return (NULL);

	matrix = (int **) malloc(sizeof(int *) * height);

	if (!matrix)
		return (NULL);

	do {
		matrix[--height] = (int *) malloc(sizeof(int) * width);

		if (!matrix[height])
			return (NULL);

		for (column = 0; column < width; ++column)
			matrix[height][column] = 0;
	} while (height);

	return (matrix);
}
