#include "holberton.h"

/**
 * print_square - print a square in the terminal
 * @size: size of square
 *
 * Return: void
 */
void print_square(int size)
{
	int linenum;
	int linelen;

	for (linenum = 0; linenum < size; ++linenum)
	{
		for (linelen = 0; linelen < size; ++linelen)
			_putchar('#');
		_putchar('\n');
	}

	if (size <= 0)
		_putchar('\n');
}
