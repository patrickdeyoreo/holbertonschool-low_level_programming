#include "holberton.h"

/**
 * strend - locate the end of a string
 * @s: the string to locate the end of
 *
 * Return: a pointer to the terminating null byte of s
 */
char *strend(char *s)
{
	return (*s ? strend(s + 1) : s);
}

/**
 * __is_palindrome - helper for is_palindrome
 * @first: a pointer to the first character of the string
 * @last: a pointer to the last (non-null) character of the string
 *
 * Return: 1 if the string is a palindrome, otherwise 0
 */
int __is_palindrome(char *first, char *last)
{
	if (first > last)
		return (1);
	if (*first != *last)
		return (0);
	return (__is_palindrome(first + 1, last - 1));
}

/**
 * is_palindrome - check if a string is a palindrome
 * @s: a pointer to the string to check
 *
 * Return: 1 if the string is a palindrome, otherwise 0
 */
int is_palindrome(char *s)
{
	return (*s ? __is_palindrome(s, strend(s) - 1) : 1);
}
