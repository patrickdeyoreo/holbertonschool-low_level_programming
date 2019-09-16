#include "holberton.h"

/**
 * _strcat - concatenate two strings
 * @dest: the string to append to
 * @src: the string to append
 *
 * Description: This function appends the string pointed to by src to the
 * string pointed to by dest, overwriting the null byte at the end of dest.
 *
 * Return: Return NULL if either src or dest is NULL. Otherwise, return dest.
 */
char *_strcat(char *dest, char *src)
{
	char *dest_end = dest;
	int src_len = 0;

	while (*dest_end)
		++dest_end;

	while (src[src_len++])
		;

	while (src_len--)
		dest_end[src_len] = src[src_len];

	return (dest);
}
