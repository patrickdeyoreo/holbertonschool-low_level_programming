#include "holberton.h"

/**
 * _atoi - convert a string to an integer
 *
 * @s: the string to convert
 *
 * Return: result of conversion
 */
int _atoi(char *s)
{
	int n = 0;
	int sign = 1;

	if (s)
	{
		while (*s)
		{
			if (*s >= '0' && *s <= '9')
				n = n * 10 + (*s - '0');
			else if (n)
				break;
			else if (*s == '-')
				sign *= -1;
			++s;
		}
	}

	return (n * sign);
}

