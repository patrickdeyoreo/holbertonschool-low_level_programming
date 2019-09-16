#include "holberton.h"

/**
 * _strcmp - compare two strings
 * @s1: a string to compare
 * @s2: the other string to compare
 *
 * Description: This functions compares two strings pointed to by s1 and s2.
 *
 * Return: 0 if s1 matches s2,
 * otherwise an integer less than 0 if s1 is less than s2,
 * otherwise an integer greater than 0 if s1 is greater than s2.
 *
 */
int _strcmp(char *s1, char *s2)
{
	for (; *s1 && *s2; ++s1, ++s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
	}
	if (*s1)
		return (1);
	if (*s2)
		return (-1);

	return (0);
}
