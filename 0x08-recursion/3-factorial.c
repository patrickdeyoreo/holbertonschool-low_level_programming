#include "holberton.h"

/**
 * factorial -
 *
 * Return:
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	return (n > 1 ? n * factorial(n - 1) : 1);
}
