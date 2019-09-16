#include "holberton.h"

/**
 * _puts - print a string, followed by a new line
 * @s: the string to print
 *
 * Return: void
 */
void _puts(char *s)
{
	while (*s)
		_putchar(*s++);

	_putchar('\n');
}
