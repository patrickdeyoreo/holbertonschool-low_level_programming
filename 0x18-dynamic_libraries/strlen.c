#include "holberton.h"

/**
 * _strlen - calculate the length of a string
 * @s: the string to measure
 *
 * Return: the string length
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s++)
		++len;

	return (len);
}
