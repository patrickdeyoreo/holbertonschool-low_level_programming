#include "holberton.h"

/**
 * rot13 - encode a string using rot13
 * @s: the string to encode
 *
 * Description: Each letter is replaced with the 13th letter after it.
 *
 * Return: pointer to the encoded string
 */
char *rot13(char *s)
{
	char *c;

	for (c = s; *c; ++c)
	{
		if ('a' <= *c && *c <= 'z')
			*c = (*c - 'a' + 13) % 26 + 'a';
		else if ('A' <= *c && *c <= 'Z')
			*c = (*c - 'A' + 13) % 26 + 'A';
	}

	return (s);
}
