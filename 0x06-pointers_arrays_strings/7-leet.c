#include "holberton.h"

/**
 * leet - encode a string into 1337.
 * @s: the string to encode
 *
 * Description: Characters are encoded as follows:
 * {'a', 'A'} -> '4'
 * {'e', 'E'} -> '3'
 * {'o', 'O'} -> '0'
 * {'t', 'T'} -> '7'
 * {'l', 'L'} -> '1'
 *
 * Return: pointer to the encoded string
 */
char *leet(char *s)
{
	char *c;
	char map[15] = {
		'a', 'A', '4',
		'e', 'E', '3',
		'o', 'O', '0',
		't', 'T', '7',
		'l', 'L', '1'
	};
	int i;

	for (c = s; *c; ++c)
	{
		for (i = 0; i < 15; i += 3)
		{
			if (*c == map[i] || *c == map[i + 1])
				*c = map[i + 2];
		}
	}

	return (s);
}
