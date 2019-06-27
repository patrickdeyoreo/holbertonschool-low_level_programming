#include "holberton.h"

/**
 * print_number - print an integer (with no trailing newline)
 * @n: integer to print
 *
 * Return: void
 */
void print_number(int n)
{
	if (n >= 0)
	{
		if (n >= 10)
			print_number(n / 10);
		_putchar('0' + n % 10);
	}
	else
	{
		_putchar('-');
		print_number(-n);
	}

}
