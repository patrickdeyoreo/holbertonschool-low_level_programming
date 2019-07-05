#include "holberton.h"

/**
 * string_toupper - change all lowercase letters of a string to uppercase
 * @s: the string the change
 *
 * Return: pointer to the resulting string
 */
char *string_toupper(char *s)
{
	char *c;

	for (c = s; *c; ++c)
	{
		if ('a' <= *c && *c <= 'z')
			*c -= 'a' - 'A';
	}

	return (s);
}
