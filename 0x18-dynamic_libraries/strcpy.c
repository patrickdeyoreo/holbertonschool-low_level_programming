#include "holberton.h"

/**
 * _strcpy - copy a string (including the terminating null-byte)
 *
 * @dest: pointer the destination buffer
 * @src: pointer to the string to copy
 *
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int len = 0;

	while (src[len++])
		;

	while (len--)
		dest[len] = src[len];

	return (dest);
}
