#include "holberton.h"

/**
 * print_line - draw a straight line in the terminal
 *
 * Return: void
 */
void print_line(int n)
{
	while (--n >= 0)
		_putchar('_');
	_putchar('\n');
}
