#include "sort.h"

/**
 * bubble_sort - sort an array in ascending order
 * @array: the start of the array
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int *position = NULL;
	int status = 0;

	if (array && size > 1)
	{
		do {
			position = array;
			status = 0;
			do {
				if (position[1] < position[0])
				{
					position[0] ^= position[1];
					position[1] ^= position[0];
					position[0] ^= position[1];
					status = 1;
					print_array(array, size);
				}
			} while (++position + 1 < array + size);
		} while (status);
	}
}
