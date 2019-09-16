#include "holberton.h"

/**
 * _isalpha - checks if the character is alphabetic
 * @c: character to check
 *
 * Return: 1 if c is an alphabetic character, otherwise 0
 */
int _isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
