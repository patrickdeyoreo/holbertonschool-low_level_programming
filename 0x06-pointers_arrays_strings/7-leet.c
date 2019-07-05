#include "holberton.h"

/**
 * leet - encodes a string into 1337.
 * @s: the string to encode
 *
 * Return: pointer to the encoded string
 */
char *leet(char *s)
{
	char table[][3]={ "4Aa", "3Ee", "0Oo", "7Tt", "1Ll" };

	int i;
	char *c;

	for (i = 0; i < 5; ++i)
	{
		for (c = table[i] + 1; *c; ++c)
		{
			if (*s == *c)
				s = table[i];
		}
	}

	return (s);
}
