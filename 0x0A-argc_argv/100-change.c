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
 * min_coins - compute the minimum number of coins needed to make change
 * @c: the amount of money to make change for in cents
 *
 * Return: the minimum number of coins needed to make change
 */
int min_coins(int c)
{
	int i;
	int d[5] = { 25, 10, 5, 2, 1 };
	int r[5] = { INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX };

	if (c < 1)
		return (0);

	for (i = 0; i < 5; ++i)
	{
		if (d[i] <= c)
		{
			r[i] = min_coins(c - d[i]);
			r[i] += 1;
		}
	}
	return (min(r, 5));
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

	printf("%d\n", cents > 0 ? min_coins(cents) : 0);

	return (0);
}
