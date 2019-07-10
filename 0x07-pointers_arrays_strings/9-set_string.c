#include "holberton.h"

/**
 * set_string - Set the value of a pointer to a char.
 * @s: pointer to the char pointer to change
 * @to: pointer to change the char pointer to
 *
 * Return: void
 */
void set_string(char **s, char *to)
{
	*s = to;
}
