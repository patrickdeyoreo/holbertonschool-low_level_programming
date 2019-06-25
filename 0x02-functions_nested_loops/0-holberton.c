#include "holberton.h"

/**
 * main - entry point
 *
 * Return: 0
 */
int main(void)
{
	char *holberton;

	for (holberton = "Holberton\n"; *holberton != '\0'; ++holberton)
		_putchar(*holberton);
	return (0);
}
