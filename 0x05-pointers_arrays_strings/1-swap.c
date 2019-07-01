#include "holberton.h"

/**
 * swap_int - swap the values of two integers
 * @a: pointer to an integer to swap
 * @b: pointer to an integer to swap
 *
 * Return: void
 */
void swap_int(int *a, int *b)
{
	if (a && b)
	{
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}
}
