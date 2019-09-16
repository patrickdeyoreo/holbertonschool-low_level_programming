#include "holberton.h"

/**
 * _strstr - locate a substring
 * @haystack: string to search
 * @needle: substring to search for
 *
 * Description: Find the first occurrence of the substring needle in the
 * string haystack. The terminating null bytes ('\0') are not compared.
 *
 * Return: a pointer to the beginning of the located substring, or
 * NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	char *h_pos, *n_pos;

	do {
		h_pos = haystack;
		n_pos = needle;
		do {
			if (!*n_pos)
				return (haystack);
			if (!*h_pos)
				return (NULL);
		} while (*h_pos++ == *n_pos++);
		++haystack;
	} while (*haystack);

	return (NULL);
}
