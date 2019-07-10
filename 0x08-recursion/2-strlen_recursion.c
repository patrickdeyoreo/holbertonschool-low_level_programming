#include "holberton.h"

/**
 * _strlen_recursion - calculate length of a string
 * @s: a pointer to the string to find the length of
 *
 * Return: the length of s
 */
int _strlen_recursion(char *s)
{
	return (*s ? _strlen_recursion(s + 1) +  1 : 0);
}
