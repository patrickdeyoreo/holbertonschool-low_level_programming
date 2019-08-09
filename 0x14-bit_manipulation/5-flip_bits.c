#include "holberton.h"

/**
 * flip_bits - count the unique bits in two values
 * @n: the first integer
 * @m: the second integer
 *
 * Return: the number of bits that differ between n and m
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	n ^= m;
	m = 0;
	while (n)
	{
		m += 1 & n;
		n >>= 1;
	}
	return (m);
}
