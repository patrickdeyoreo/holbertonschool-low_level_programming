#include "holberton.h"

/**
 * print_numbers - print numbers 0 through 9
 *
 * Return: void
 */
void print_numbers(void)
{
	char i;

	for (i = '0'; i <= '9'; ++i)
		_putchar(i);
	_putchar('\n');
}
