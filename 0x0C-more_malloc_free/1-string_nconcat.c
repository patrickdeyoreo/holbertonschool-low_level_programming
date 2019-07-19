#include "holberton.h"

/**
 * min - get the lesser of two values
 * @a: a positive integer
 * @b: another positive integer
 *
 * Return: whichever value is less (either if they're equal)
 */
unsigned int min(unsigned int a, unsigned int b)
{
	return (a < b ? a : b);
}


/**
 * _strlen - calculate the length of a string
 * @s: the string to measure
 *
 * Return: the length of the string s
 */
unsigned int _strlen(const char *s)
{
	unsigned int len = 0;

	while (s[len])
		++len;

	return (len);
}


/**
 * string_nconcat - concatenate two strings
 * @s1: the first string
 * @s2: the second string
 * @n: the maximum number of bytes to use from s2
 *
 * Description: Copy s1 followed by the first n bytes of s2 into dynamically
 * allocated memory, and append a terminating null-byte. If n is greater than
 * or equal to the length of the string s2, use only the bytes from s2 up to
 * it's terminating null-byte. s2 is NULL, treat is as an empty string.
 *
 * Return: If memory allocation fails, return NULL. Otherwise, return a pointer
 * to the first character of the new string.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *cat;
	unsigned int s1_len = _strlen(s1);
	unsigned int s2_len = s2 ? min(_strlen(s2), n) : 0;

	cat = malloc(sizeof (char) * s1_len + s2_len + 1);
	if (!cat)
		return (NULL);

	for (n = 0; n < s1_len; ++n, ++cat)
		*cat = s1[n];

	for (n = 0; n < s2_len; ++n, ++cat)
		*cat = s2[n];

	*cat = '\0';

	return (cat - s1_len - s2_len);
}
