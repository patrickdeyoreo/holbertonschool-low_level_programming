#include "holberton.h"

/**
 * print_rev - print a string, in reverse, followed by a new line
 * @s: the string to print
 *
 * Return: void
 */
void print_rev(char *s)
{
	if (s)
	{
		if (*s)
		{
			print_rev(s + 1);
			_putchar(*s);
		}
	}
}
