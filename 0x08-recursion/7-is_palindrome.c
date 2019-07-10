#include "holberton.h"

/**
 * strend - find the end of a string
 * @s: the string to find the end of
 *
 * Return: a pointer to the terminating null byte of s
 */
char *strend(char *s)
{
	return (*s ? strend(s + 1) : s);
}

/**
 * __is_palindrome -
 *
 * Return:
 */
int __is_palindrome(char *first, char *last)
{
	if (first > last)
		return 1;
	if (*first != *last)
		return 0;
	return (__is_palindrome(first + 1, last - 1));
}

/**
 * is_palindrome -
 *
 * Return:
 */
int is_palindrome(char *s)
{
	return (*s ? __is_palindrome(s, strend(s) - 1) : 1);
}
