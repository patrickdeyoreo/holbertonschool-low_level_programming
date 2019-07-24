#include "function_pointers.h"

/**
 * array_iterator - perform an action on each element of an array
 * @array: the array to iterate over
 * @size: the size of array
 * @action: the action to perform on each array element
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	if (array && action)
	{
		while (size--)
			action(*array++);
	}
}
