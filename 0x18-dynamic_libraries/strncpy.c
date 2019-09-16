#include "holberton.h"

/**
 * _strncpy - copy a string
 * @dest: the buffer to copy to
 * @src: the string to copy
 * @n: the maximum number of bytes to copy from src
 *
 * Description: This function copies at most n bytes of the string pointed
 * to by src to the buffer pointed to by dest. If the length of src is less
 * than n, this function will write null bytes until a n bytes are wrtten.
 *
 * Return: a pointer to the destination string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *dest_end = dest;
	int src_len = 0;

	while (src_len < n && src[src_len])
		++src_len;

	if (src + src_len < dest || dest + n < src)
	{
		for (; src_len; --src_len, --n)
			*dest_end++ = *src++;

		for (; n; --n)
			*dest_end++ = '\0';
	}

	return (dest);
}
