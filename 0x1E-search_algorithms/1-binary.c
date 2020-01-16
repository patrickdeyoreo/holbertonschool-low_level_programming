#include "search_algos.h"

/**
 * print_array - print a slice of an array
 * @array: array of values to print
 * @lower: lower bound
 * @upper: upper bound
 */
static void print_array(int *array, size_t lower, size_t upper)
{
	while (lower < upper)
	{
		printf("%d", array[lower]);
		printf(++lower < upper ? ", " : "\n");
	}
}

/**
 * _binary_search - search for a value in a sorted array of integers
 * @array: array of values to search
 * @value: value to find
 * @lower: lower bound
 * @upper: upper bound
 *
 * Return: If value is not present in array or array is NULL, return -1.
 * Otherwise, returh the index where value is located.
 */
int _binary_search(int *array, int value, size_t lower, size_t upper)
{
	size_t middle = (lower + upper - 1) / 2;

	printf("Searching in array: ");
	print_array(array, lower, upper);

	if (upper - lower == 1)
		return (array[middle] == value ? (int) middle : -1);
	if (array[middle] < value)
		return (_binary_search(array, value, middle + 1, upper));
	if (array[middle] > value)
		return (_binary_search(array, value, lower, middle));
	return (middle);
}

/**
 * binary_search - search for a value in a sorted array of integers
 * @array: array of values to search
 * @size: size of the array
 * @value: value to find
 *
 * Return: If value is not present in array or array is NULL, return -1.
 * Otherwise, returh the first index where value is located.
 */
int binary_search(int *array, size_t size, int value)
{
	return (array && size ? _binary_search(array, value, 0, size) : -1);
}
