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
 * isnumber - check if a string is a number
 * @s: a pointer to the string to check
 *
 * Return: 1 if the string is a number,
 * otherwise 0
 */
int isnumber(char *s)
{
	if (*s == '-')
		++s;
	while ('0' <= *s && *s <= '9')
		++s;
	return (!*s);
}


/**
 * main - print the name of the program
 * @argc: size of the argument vector
 * @argv: program name and arguments
 *
 * Return: 1 if called with non-integer arguments,
 * otherwise 0
 */
int main(int argc, char *argv[])
{
	int sum;

	for (sum = 0; --argc; sum += atoi(*argv))
	{
		if (!isnumber(*(++argv)))
		{
			_puts("Error");
			return (1);
		}
	}

	print_number(sum);
	_putchar('\n');

	return (0);
}
