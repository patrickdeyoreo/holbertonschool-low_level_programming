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
	int len = 0;
	int pos = 0;

	if (dest && src)
	{
		while (*(src + len))
			++len;

		if (src + len < dest || dest + len < src)
		{
			do {
				*(dest + pos++) = *src++;
			} while (len--);
		}
	}

	return (dest);
}
