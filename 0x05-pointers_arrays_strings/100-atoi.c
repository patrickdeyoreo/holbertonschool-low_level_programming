#include "holberton.h"
#include <limits.h>

/**
 * _atoi - convert a string to an integer
 * @s: the string to convert
 *
 * Return: result of conversion
 */
int _atoi(char *s)
{
	unsigned int n = 0;
	int sign = 1;
	int flag = 0;

	while (*s)
	{
		if (*s >= '0' && *s <= '9')
		{
			flag = 1;
			if (sign > 0)
			{
				if (INT_MAX / 10 < (int) n)
					return (INT_MAX);
				n *= 10;
				if (INT_MAX - (*s - '0') < (int) n)
					return (INT_MAX);
			}
			else
			{
				if (INT_MIN / 10 < (int) -n)
					return (INT_MIN);
				n *= 10;
				if (INT_MIN + (*s - '0') > (int) -n)
					return (INT_MIN);
			}
			n += (*s - '0');
		}
		else if (flag)
		{
			break;
		}
		else if (*s == '-')
		{
			sign *= -1;
		}
		++s;
	}

	return (n * sign);
}
