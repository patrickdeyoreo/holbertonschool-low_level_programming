#include "holberton.h"

/**
 * _pow_recursion -
 *
 * Return:
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return -1;
	return (y > 1 ? x * _pow_recursion(x, y - 1) : y > 0 ? x : 1);
}
