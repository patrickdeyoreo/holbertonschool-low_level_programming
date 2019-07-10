#include "holberton.h"

/**
 * __sqrt_recursion -
 *
 * Return:
 */
int __sqrt_recursion(int n, int m)
{
	if (m * m < n)
		return __sqrt_recursion(n, m + 1);
	return (m * m == n ? m : -1);

}

/**
 * _sqrt_recursion -
 *
 * Return:
 */
int _sqrt_recursion(int n)
{
	return __sqrt_recursion(n, 0);
}
