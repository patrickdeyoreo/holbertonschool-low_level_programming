#include "holberton.h"
#include <limits.h>


/**
 * print_number - print an integer
 * @n: the integer to print
 *
 * Return: void
 */
void print_number(int n)
{
	if (n > -1)
	{
		if (n > 9)
			print_number(n / 10);
		_putchar('0' + n % 10);
	}
	else
	{
		_putchar('-');
		if (n < -9)
			print_number(n / -10);
		_putchar('0' - n % 10);
	}
}


/**
 * _puts - print a string, followed by a new line
 * @str: the string to print
 *
 * Return: void
 */
void _puts(char *str)
{
	while (*str)
		_putchar(*str++);
	_putchar('\n');
}


/**
 * main - print the product of two numbers
 * @argc: size of the argument vector
 * @argv: program name and arguments
 *
 * Return: 1 if called with anything other than 2 arguments,
 * otherwise 0
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		_puts("Error");
		return (1);
	}

	print_number(atoi(argv[1]) * atoi(argv[2]));
	_putchar('\n');

	return (0);
}
