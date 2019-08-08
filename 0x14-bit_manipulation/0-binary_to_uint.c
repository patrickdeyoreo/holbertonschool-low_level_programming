#include "holberton.h"

/**
 * binary_to_uint - convert a binary string to an integer
 * @b: the string to convert
 *
 * Return: the converted number, or 0 if b contains a character
 * other than '0' and '1'
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int n = 0;

	if (!b)
		return (0);

	while (*b)
	{
		n <<= 1;
		if (*b == '1')
			n += 1;
		else if (*b != '0')
			return (0);
		++b;
	}
	return (n);
}
