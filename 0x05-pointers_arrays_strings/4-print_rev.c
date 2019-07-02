#include "holberton.h"

/**
 * print_rev - print a string, in reverse, followed by a new line
 * @s: the string to print
 *
 * Return: void
 */
void print_rev(char *s)
{
	char *t = s;

	if (s)
	{
		while (*t)
			++t;
		while (s < t--)
			_putchar(*t);
		_putchar('\n');
	}
}
