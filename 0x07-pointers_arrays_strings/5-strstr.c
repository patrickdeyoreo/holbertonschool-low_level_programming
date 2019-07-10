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
	int i;

	for ( ; *haystack; haystack += i + 1)
	{
		for (i = 0; haystack[i] == needle[i]; ++i)
		{
			if (!needle[i])
				return (haystack);
		}
	}
	return (NULL);
}
