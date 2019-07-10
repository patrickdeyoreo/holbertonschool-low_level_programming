#include "holberton.h"

/**
 * _strlen_recursion -
 *
 * Return:
 */
int _strlen_recursion(char *s)
{
	return (*s ? _strlen_recursion(s + 1) +  1 : 0);
}
