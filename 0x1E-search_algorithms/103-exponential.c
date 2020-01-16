#include "search_algos.h"

#define FACTOR 2

#define VALUE_CHECKED(array, index) \
	printf("Value checked array[%lu] = [%d]\n", (index), (array)[index])

#define VALUE_BOUNDED(lower, upper) \
	printf("Value found between indexes [%lu] and [%lu]\n", (lower), (upper))

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
 * _binary_search - search for a value in a sorted array of integers
 * @array: the array of values
 * @lo: the smallest index
 * @hi: the greatest index
 * @value: the value to locate
 *
 * Return: If value is not present in array or array is NULL, return -1.
 * Otherwise, returh the first index where value is located.
 */
static int _binary_search(int *array, size_t lo, size_t hi, int value)
{
	size_t mid;

	while (1)
	{
		print_array(array, lo, hi);

		if (lo == hi)
			return (array[lo] == value ? (int) lo : -1);

		mid = (lo + hi) / 2;

		if (array[mid] == value)
			return (mid);

		if (array[mid] < value)
			lo = mid + 1;
		else
			hi = mid - 1;
	}
}

/**
 * exponential_search - search for a value in a sorted array of integers
 * @array: the array of values
 * @size: the number of values
 * @value: the value to locate
 *
 * Return: If value is not present in array or array is NULL, return -1.
 * Otherwise, returh the first index where value is located.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i = 1;

	if (array && size)
	{
		while (i < size && array[i] < value)
		{
			VALUE_CHECKED(array, i);
			i *= 2;
		}
		VALUE_BOUNDED(i / 2, i - 1);
		if (size > i)
			size = i;

		return (_binary_search(array, i / 2, size - 1, value));
	}
	return (-1);
}
