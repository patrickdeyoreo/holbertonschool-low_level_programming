#include "holberton.h"

/**
 * _is_prime_number -
 *
 * Return:
 */
int __is_prime_number(int n, int m)
{
	if (n % m == 0)
		return 0;
	if (n < m * 2)
		return 1;

	return __is_prime_number(n, m + 1);
}

/**
 * is_prime_number -
 *
 * Return:
 */
int is_prime_number(int n)
{
	if (n < 4)
		return (n > 0);

	return __is_prime_number(n, 2);
}
