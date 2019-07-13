#include "holberton.h"
#include <limits.h>

/**
 * _atoi - convert a string to an integer
 * @s: the string to convert
 *
 * Return: result of conversion
 */
int _atoi(char *s)
{
	unsigned int n = 0;
	int sign = 1;
	int flag = 0;

	while (*s)
	{
		if (*s >= '0' && *s <= '9')
		{
			flag = 1;
			if (sign > 0)
			{
				if (INT_MAX / 10 < (int) n)
					return (INT_MAX);
				n *= 10;
				if (INT_MAX - (*s - '0') < (int) n)
					return (INT_MAX);
			}
			else
			{
				if (INT_MIN / 10 < (int) -n)
					return (INT_MIN);
				n *= 10;
				if (INT_MIN + (*s - '0') > (int) -n)
					return (INT_MIN);
			}
			n += (*s - '0');
		}
		else if (flag)
		{
			break;
		}
		else if (*s == '-')
		{
			sign *= -1;
		}
		++s;
	}

	return (n * sign);
}

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
 * main - print the name of the program
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

	print_number(_atoi(argv[1]) * _atoi(argv[2]));
	_putchar('\n');

	return (0);
}
