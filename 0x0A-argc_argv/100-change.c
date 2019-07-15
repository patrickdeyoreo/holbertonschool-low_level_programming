#include "holberton.h"

/**
 * subtract_largest_coin - find min number of coins needed to make change
 * @cents: the amount of money to make change for in cents
 *
 * Return: the minimum number of coins needed to make change
 */
int subtract_largest_coin(int cents)
{
	if (cents - 25 > -1)
		return (cents - 25);

	if (cents - 10 > -1)
		return (cents - 10);

	if (cents - 5 > -1)
		return (cents - 5);

	if (cents - 2 > -1)
		return (cents - 2);

	if (cents - 1 > -1)
		return (cents - 1);

	return (0);
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
	int cents, coins;

	if (argc != 2)
	{
		puts("Error");
		return (1);
	}

	for (cents = atoi(argv[1]), coins = 0; cents > 0; ++coins)
		cents = subtract_largest_coin(cents);

	printf("%d\n", coins);

	return (0);
}
