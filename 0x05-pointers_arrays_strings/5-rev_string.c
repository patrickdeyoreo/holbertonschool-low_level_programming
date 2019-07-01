#include "holberton.h"

/**
 * rev_string - reverse a string
 * @s: the string to reverse
 *
 * Return: void
 */
void rev_string(char *s)
{
	char *t;

	if (s)
	{
		for (t = s; *t; ++t)
			;

		while (s < --t)
		{
			*s ^= *t;
			*t ^= *s;
			*s ^= *t;
			++s;
		}
	}
}
