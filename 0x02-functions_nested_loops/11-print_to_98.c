#include "holberton.h"
#include <stdio.h>

/**
 * print_to_98 - print all integers from given value to 98 (inclusive)
 * @n: The start of the range
 *
 * Return: void
 */
void print_to_98(int n)
{
	if (n == 98)
	{
		printf("%d\n", n);
	}
	else
	{
		printf("%d, ", n);
		print_to_98((n < 98) ? n + 1 : n - 1);
	}
}
