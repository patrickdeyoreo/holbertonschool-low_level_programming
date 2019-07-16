#include "holberton.h"

/**
 * free_grid - free a 2-dimensional array created by alloc_grid
 * @grid: a pointer to the first column of the first row of the array
 * @height: the number of rows in the array
 *
 * Return: void
 */
void free_grid(int **grid, int height)
{
	while (height)
		free(grid[--height]);
	free(grid);
}
