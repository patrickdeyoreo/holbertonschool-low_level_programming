#include "holberton.h"

/**
 * _strlen - calculate the length of a string
 * @s: the string to compute the length of
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int len;

	if (s)
	{
		for (len = 0; *(s + len); ++len)
			;
	}

	return (len);
}
