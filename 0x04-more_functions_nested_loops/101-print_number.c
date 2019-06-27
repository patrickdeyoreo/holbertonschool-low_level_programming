#include "holberton.h"

/**
 * print_number - print an integer (with no trailing newline)
 * @n: integer to print
 *
 * Return: void
 */
void print_number(int n)
{
	unsigned int m;

	if (n >= 0)
	{
		if (n >= 10)
			print_number(n / 10);
		_putchar('0' + n % 10);
	}
	else
	{
		_putchar('-');
		m = -1 * n;
		if (m >= 10)
			print_number(m / 10);
		_putchar('0' + m % 10);
	}

}
