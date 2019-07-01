#include "holberton.h"

/**
 * puts_half - print the second half of a string
 * @str: the string to print
 *
 * Return: void
 */
void puts_half(char *str)
{
	int len;

	if (str)
	{
		for (len = 0; *(str + len); ++len)
			;
		for (str += (len + 1) / 2; *str; ++str)
			_putchar(*str);
		_putchar('\n');
	}
}
