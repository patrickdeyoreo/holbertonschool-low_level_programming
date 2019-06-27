#include "holberton.h"

/**
 * _isupper - check if character is uppercase
 * @c: character to check
 *
 * Return: 1 if c is uppercase,
 * 0 otherwise.
 */
int _isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
