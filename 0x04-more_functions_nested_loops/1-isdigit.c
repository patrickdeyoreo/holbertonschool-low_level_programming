#include "holberton.h"

/**
 * _isdigit - check if character is a digit
 * @c: character to check
 *
 * Return: 1 if c is a digit,
 * 0 otherwise.
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
