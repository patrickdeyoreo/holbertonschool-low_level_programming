#include "holberton.h"

/**
 * print_sign - print the sign of a numeric value
 * @n: The value to test
 *
 * Return: 1 if n is positive.
 * -1 if n is negative.
 *  Otherwise 0.
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-');
		return (-1);
	}
	else
	{
		_putchar('0');
		return (0);
	}
}
