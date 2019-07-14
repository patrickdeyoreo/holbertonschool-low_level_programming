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
 * count_coins - compute the minimum number of coins needed to make change
 * @cents: the amount of money in cents
 *
 * Return: the number of coins needed to make change
 */
int count_coins(int cents)
{
	int coins = 0;

	if (cents >= 25)
	{
		coins += cents / 25;
		cents %= 25;
	}
	if (cents >= 10)
	{
		coins += cents / 10;
		cents %= 10;
	}
	if (cents >= 5)
	{
		coins += cents / 5;
		cents %= 5;
	}
	if (cents >= 2)
	{
		coins += cents / 2;
		cents %= 2;
	}
	if (cents >= 1)
		coins += cents;

	return (coins);
}


/**
 * main - print the minimum number of coins needed to make change
 * @argc: size of the argument vector
 * @argv: program name and arguments
 *
 * Return: 1 if given something other than a single argument,
 * otherwise 0
 */
int main(int argc, char *argv[])
{
	int cents;

	if (argc != 2)
	{
		_puts("Error");
		return (1);
	}

	cents = atoi(argv[1]);

	printf("%d\n", cents > 0 ? count_coins(cents) : 0);

	_putchar('\n');

	return (0);
}
