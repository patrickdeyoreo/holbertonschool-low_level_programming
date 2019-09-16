#include "holberton.h"

/**
 * _abs - compute the absolute value of a number
 * @n: The value to operate on
 *
 * Return: The absolute value of i
 */
int _abs(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}
