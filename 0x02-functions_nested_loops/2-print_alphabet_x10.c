#include "holberton.h"

/**
 * print_alphabet_x10 - print alphabet 10 times
 *
 * Description: print lowercase alphabet followed by newline 10 times
 * Return: void
 */
void print_alphabet_x10(void)
{
	int i;
	int c;

	for (i = 0; i < 10; ++i)
	{
		for (c = 'a'; c <= 'z'; ++c)
			_putchar(c);
		_putchar('\n');
	}
}
