#include "holberton.h"

/**
 * print_alphabet - print the alphabet
 *
 * Description: print the alphabet, in lowercase, followed by a new line
 * Return: void
 */

void print_alphabet(void)
{
	int c;

	for (c = 'a'; c <= 'z'; ++c)
		_putchar(c);
	_putchar('\n');
}
