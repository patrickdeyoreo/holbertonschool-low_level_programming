#include "search_algos.h"

/**
 * print_array - print the values in an array
 * @array: array of values to print
 * @lo: the smallest index to print
 * @hi: the greatest index to print
 */
static void print_array(int *array, size_t lo, size_t hi)
{
	printf("Searching in array: ");
	while (lo <= hi)
	{
		if (lo < hi)
			printf("%d, ", array[lo++]);
		else
			printf("%d\n", array[lo++]);
	}
}

/**
 * _binary_search - search for a value in a sorted array of integers
 * @array: array of values to search
 * @lo: the smallest index to print
 * @hi: the greatest index to print
 * @value: value to find
 *
 * Return: If value is not present in array or array is NULL, return -1.
 * Otherwise, returh the first index where value is located.
 */
int _binary_search(int *array, size_t lo, size_t hi, int value)
{
	size_t mid = (lo + hi) / 2;

	print_array(array, lo, hi);

	if (lo == hi)
		return (array[mid] == value ? (int) mid : -1);
	if (array[mid] < value)
		return (_binary_search(array, mid + 1, hi, value));
	if (array[mid] > value)
		return (_binary_search(array, lo, mid - 1, value));

	return (mid);
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
	return (array && size ? _binary_search(array, 0, size - 1, value) : -1);
}
