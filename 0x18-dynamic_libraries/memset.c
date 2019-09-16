#include "holberton.h"

/**
 * _memset - fill memory with a constant byte
 * @s: a pointer to a memory area
 * @b: the byte to write to memory
 * @n: the number of bytes to write
 *
 * Return: a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
		s[i++] = b;

	return (s);
}
