#include "search_algos.h"

/**
 * print_array - print the values in an array
 * @array: the array of values
 * @lo: the smallest index
 * @hi: the greatest index
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
 * _advanced_binary - search for a value in a sorted array of integers
 * @array: the array of values
 * @lo: the smallest index
 * @hi: the greatest index
 * @value: the value to locate
 *
 * Return: If value is not present in array or array is NULL, return -1.
 * Otherwise, returh the first index where value is located.
 */
static int _advanced_binary(int *array, size_t lo, size_t hi, int value)
{
	size_t mid = (lo + hi) / 2;

	if (lo > hi)
		return (-1);

	print_array(array, lo, hi);
	if (array[mid] < value)
		return (_advanced_binary(array, mid + 1, hi, value));
	if (array[mid] > value)
		return (_advanced_binary(array, lo, mid, value));
	if (array[mid - 1] == value)
		return (_advanced_binary(array, lo, mid, value));
	return (mid);
}

/**
 * advanced_binary - search for a value in a sorted array of integers
 * @array: the array of values
 * @size: the number of values
 * @value: the value to locate
 *
 * Return: If value is not present in array or array is NULL, return -1.
 * Otherwise, returh the first index where value is located.
 */
int advanced_binary(int *array, size_t size, int value)
{
	return (array && size ? _advanced_binary(array, 0, size - 1, value) : -1);
}
