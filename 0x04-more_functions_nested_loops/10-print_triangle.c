#include "holberton.h"

/**
 * print_triangle - print a triangle in the terminal
 * @size: base & height of triangle
 *
 * Return: void
 */
void print_triangle(int size)
{
	int linenum;
	int linelen;

	for (linenum = 1; linenum <= size; ++linenum)
	{
		for (linelen = size; linelen > linenum; --linelen)
			_putchar(' ');
		for ( ; linelen > 0; --linelen)
			_putchar('#');
		_putchar('\n');
	}

	if (size <= 0)
		_putchar('\n');
}
