#include "holberton.h"

/**
 * rev_string - reverse a string
 * @s: the string to reverse
 *
 * Return: void
 */
void rev_string(char *s)
{
	char *t = s;

	if (s)
	{
		while (*t)
			++t;

		while (s < --t)
		{
			*s ^= *t;
			*t ^= *s;
			*s ^= *t;
			++s;
		}
	}
}
