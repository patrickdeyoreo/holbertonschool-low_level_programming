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
	char *hpos, *npos;

	do {
		hpos = haystack;
		npos = needle;
		do {
			if (!*npos)
				return (haystack);
			if (!*hpos)
				return (NULL);
		} while (*hpos++ == *npos++);
	} while (*(++haystack));

	return (NULL);
}
