#include "holberton.h"


/**
 * _puts - print a string, followed by a new line
 * @str: the string to print
 *
 * Return: void
 */
void _puts(char *str)
{
	while (*str)
		_putchar(*str++);
	_putchar('\n');
}


/**
 * main - print the program name and arguments
 * @argc: size of the argument vector
 * @argv: program name and arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	do {
		_puts(*argv++);
	} while (--argc > 0);

	return (0);
}
