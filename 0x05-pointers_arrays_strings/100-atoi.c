#include "holberton.h"
#include <limits.h>

/**
 * _atoi - convert a string to an integer
 *
 * @s: the string to convert
 *
 * Return: result of conversion
 */
int _atoi(char *s)
{
	unsigned int n = 0;
	int sign = 1;

	if (s)
	{
		while (*s)
		{
			if (*s >= '0' && *s <= '9')
			{
				n = n * 10 + (*s - '0');
				if (sign > 0)
				{
					if (n >= INT_MAX)
						return INT_MAX;
				}
				else
				{
					if ((n >> (sizeof(unsigned int) - 1)))
						return INT_MIN;
				}
			}
			else if (n)
				break;
			else if (*s == '-')
				sign *= -1;
			++s;
		}
	}

	return (n * sign);
}
