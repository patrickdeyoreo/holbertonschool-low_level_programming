#include <stdio.h>


/**
 * isprime - check if integer is divisible by any number other than 1.
 * @n: integer to check
 *
 * Return: 1 if n is prime,
 * otherwise 0.
 */
int isprime(long n)
{
	long i;
	long i_max = n / 2;

	for (i = 2; i < i_max; ++i)
	{
		if (n % i == 0)
			return (0);
	}
	return (1);
}


/**
 * largest_prime_factor - find the largest prime_factor of an integer.
 * @n: integer to factor
 *
 * Return: largest prime factor of n.
 */
long largest_prime_factor(long n)
{
	long i = 2;

	while (!isprime(n))
	{
		while (n % i || !isprime(i))
			++i;
		n /= i;
	}
	return (n);
}


/**
 * main - find and print the largest prime factor of 612852475143
 *
 * Return: Always 0.
 */
int main(void)
{
	printf("%ld\n", largest_prime_factor(612852475143));
	return (0);
}
