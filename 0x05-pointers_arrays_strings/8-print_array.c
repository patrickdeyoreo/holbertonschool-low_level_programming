#include "holberton.h"
#include <stdio.h>

/**
 * print_array - print elements of an array of integers
 * @a: the start of an array of integers
 * @n: the number of array elements to print
 *
 * Return: void
 */
void print_array(int *a, int n)
{
	if (a)
	{
		while (n > 0)
		{
			printf("%d", *a++);
			if (--n)
				printf(", ");
		}
		putchar('\n');
	}
}
