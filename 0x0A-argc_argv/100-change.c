#include "holberton.h"
#include <limits.h>

/**
 * min - get the minimum value of a set of integers
 * @v: the values to compare
 * @c: the number of values
 *
 * Return: the minimum value
 */
int min(int *v, unsigned int c)
{
	int r = *v;

	while (--c != 0)
	{
		if (*(++v) < r)
			r = *v;
	}
	return (r);
}

/**
 * m5 - get the minimum value of a set of integers
 * @a: a value to compare
 * @b: a value to compare
 * @c: a value to compare
 * @d: a value to compare
 * @e: a value to compare
 *
 * Return: the minimum value
 */
int m5(int a, int b, int c, int d, int e)
{
	int values[5];

	values[0] = a;
	values[1] = b;
	values[2] = c;
	values[3] = d;
	values[4] = e;
	return (min(values, 5));
}

/**
 * coins - compute the minimum number of coins needed to make change
 * @c: the amount of money to make change for in cents
 *
 * Return: the minimum number of coins needed to make change
 */
int coins(int c)
{
	if (c < 0)
		return (INT_MAX);

	if (c < 1)
		return (0);

	return (1 + m5(coins(c - 25), coins(c - 10),
			coins(c - 5), coins(c - 2), coins(c - 1)));
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
		puts("Error");
		return (1);
	}

	cents = atoi(argv[1]);

	printf("%d\n", cents > 0 ? coins(cents) : 0);

	return (0);
}
