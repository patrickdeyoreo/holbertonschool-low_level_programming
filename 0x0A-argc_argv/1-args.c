#include "holberton.h"

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
 * main - print the number of arguments received
 * @argc: size of the argument vector
 * @argv: program name and arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[] __attribute__ ((unused)))
{
	print_number(argc - 1);
	_putchar('\n');

	return (0);
}

