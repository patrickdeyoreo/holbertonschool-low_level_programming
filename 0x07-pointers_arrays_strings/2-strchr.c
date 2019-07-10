#include "holberton.h"

/**
 * _strchr - locate character in string
 * @s: a pointer to the string to search
 * @c: the character to search for
 *
 * Return: If a match is found, return a pointer to it.
 * Otherwise, return NULL.
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s++ == c)
			return (s);
	}
	return (NULL);
}
