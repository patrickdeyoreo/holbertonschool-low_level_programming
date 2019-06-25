#include "holberton.h"

/**
 * print_last_digit - print the last digit of an integer
 * @n: The value to operate on
 *
 * Return: The last digit of n.
 */
int print_last_digit(int n)
{
	n = (n < 0 ? -n : n) % 10;
	_putchar('0' + n);
	return (n);
}
