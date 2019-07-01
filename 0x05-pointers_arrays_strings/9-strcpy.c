#include "holberton.h"

/**
 * _strcpy - copy a string (including the terminating null-byte)
 *
 * @dest: the buffer to which the string should be copied
 * @src: the string to copy
 *
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int len;
	int pos;

	if (dest && src)
	{
		for (len = 0; *(src + len); ++len)
			;

		if (src + len < dest || dest + len < src)
		{
			pos = 0;
			do {
				*(dest + pos++) = *src;
			} while (*src++);
		}
	}

	return (dest);
}
