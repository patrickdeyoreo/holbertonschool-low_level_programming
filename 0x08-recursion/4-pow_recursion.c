#include "holberton.h"

/**
 * _pow_recursion - compute x to the power of y
 * @x: the base
 * @y: the exponent
 *
 * Return: x to the power of y
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	return (y > 0 ? x * _pow_recursion(x, y - 1) : 1);
}
