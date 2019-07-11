#include "holberton.h"

/**
 * _strchr - locate character in string
 * @s: a pointer to the string to search
 * @c: the character to search for
 *
 * Return: a pointer to the first match,
 * or NULL if no matches are found.
 */
char *_strchr(char *s, char c)
{
	if (*s == c)
		return (s);
	if (*s)
		return (_strchr(s + 1, c));

	return (NULL);
}


/**
 * _strlen - calculate length of a string
 * @s: a pointer to the string to find the length of
 *
 * Return: the length of s
 */
unsigned int _strlen(char *s)
{
	return (*s ? _strlen(s + 1) +  1 : 0);
}


/**
 * _strncmp - compare two strings
 * @s1: a string to compare
 * @s2: the other string to compare
 * @n: the max number of bytes to compare
 *
 * Description: Compare at most n bytes of the strings pointed to by s1 and s2.
 *
 * Return: 0 if s1 matches s2,
 * otherwise an integer less than 0 if s1 is less than s2,
 * otherwise an integer greater than 0 if s1 is greater than s2.
 *
 */
char _strncmp(char *s1, char *s2, unsigned int n)
{
	if (!n)
		return (0);

	if (*s1 == *s2)
		return (*s1 ? _strncmp(s1 + 1, s2 + 1, n - 1) : 0);

	if (*s1)
		return (1);

	if (*s2)
		return (-1);

	return (*s1 - *s2);
}


/**
 * _strnstr - locate a substring
 * @s: a pointer to the string to search
 * @ss: a pointer to the substring to search for
 * @s_len: the number of bytes to check in s
 * @ss_len: the number of bytes to match in ss
 *
 * Description: Find the first occurrence of the substring needle in the
 * string haystack. The terminating null bytes ('\0') are not compared.
 *
 * Return: a pointer to the beginning of the located substring, or
 * NULL if the substring is not found.
 */
char *_strnstr(char *s, char *ss, unsigned int s_len, unsigned int ss_len)
{
	if (!ss_len)
		return (s);

	if (s_len < ss_len)
		return (NULL);

	if (!_strncmp(s, ss, ss_len))
		return (s);

	return (_strnstr(s + 1, ss, s_len - 1, ss_len));
}


/**
 * _wildcmp - compare two strings
 * @s1: a pointer to search string
 * @s2: a pointer to the second pattern
 * @wild_prev: a pointer to the previous wildcard
 *
 * Description: Compare s1 with s2, where s2 may contain the wildcard '*'
 * which matches any string (including the empty string).
 *
 * Return: 1 if the pattern matches the string, otherwise 0.
 */
int _wildcmp(char *s1, char *s2, char *wild_prev)
{
	char *wild = _strchr(s2, '*');
	unsigned int s1_len = _strlen(s1);
	unsigned int s2_len = _strlen(s2);

	if (!wild)
	{
		if (!wild_prev)
		{
			if (s1_len != s2_len)
				return (0);

			return (!_strncmp(s1, s2, s1_len));
		}

		if (s1_len < s2_len)
			return (0);

		return (!_strncmp(s1 + (s1_len - s2_len), s2, s2_len));
	}

	if (!wild_prev)
	{
		if (_strncmp(s1, s2, wild - s2))
			return (0);

		return (_wildcmp(s1 + (wild - s2), wild + 1, wild));
	}

	s1 = _strnstr(s1, s2, _strlen(s1), (wild - s2));

	if (!s1)
		return (0);

	if (_wildcmp(s1 + (wild - s2), wild + 1, wild))
		return (1);

	return (_wildcmp(s1 + 1, s2, wild_prev));
}


/**
 * wildcmp - compare two strings
 * @s1: a pointer to search string
 * @s2: a pointer to the second pattern
 *
 * Description: Compare s1 with s2, where s2 may contain the wildcard '*'
 * which matches any string (including the empty string).
 *
 * Return: 1 if the pattern matches the string, otherwise 0.
 */
int wildcmp(char *s1, char *s2)
{
	return (_wildcmp(s1, s2, NULL));
}
