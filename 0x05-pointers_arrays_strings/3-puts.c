#include "holberton.h"

/**
 * _puts - print a string, followed by a new line
 * @str: the string to print
 *
 * Return: void
 */
void _puts(char *str)
{
	if (!str)
	{
		while (*str != '\0')
			_putchar(*str++);
		_putchar('\n');
	}
}
