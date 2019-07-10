#include "holberton.h"

/**
 * _memcpy - copy a memory area
 * @dest: a pointer to the start of the target area
 * @src: a pointer to the start of the source area
 * @n: the number of bytes to copy
 *
 * Description: This function copies n bytes from memory area src to memory
 * area dest. The memory areas must not overlap.
 *
 * Return: a pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	for (i = 0; i < n; ++i, ++src)
		dest[i] = *src;
	return (dest);
}
