#include "search_algos.h"

#define PRINT_CHECKED(array, index) \
	(printf("Value checked array[%lu] = [%d]\n", (mid), (array)[mid]))

#define PRINT_NOT_IN_RANGE(index) \
	(printf("Value checked array[%lu] is out of range\n", (mid)))

#define MID_POS(arr, lo, hi, val) \
	((lo) + (double)((hi) - (lo)) / ((arr)[hi] - (arr)[lo]) * ((val) - (arr)[lo]))

/**
 * interpolation_search - search for a value in a sorted array of integers
 * @array: the array of values
 * @size: the number of values
 * @value: the value to locate
 *
 * Return: If value is not present in array or array is NULL, return -1.
 * Otherwise, returh the first index where value is located.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t lo = 0, hi = size - 1, mid = 0;

	if (array && size)
	{
		while (1)
		{
			mid = MID_POS(array, lo, hi, value);

			if (mid > hi)
				break;

			PRINT_CHECKED(array, mid);

			if (lo == hi)
				return (array[lo] == value ? (int) lo : -1);

			if (array[mid] == value)
				return (mid);

			if (array[mid] < value)
				lo = mid + 1;
			else
				hi = mid - 1;
		}
		PRINT_NOT_IN_RANGE(mid);
	}
	return (-1);
}
