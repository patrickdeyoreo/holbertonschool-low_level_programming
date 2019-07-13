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
 * main - print the name of the program
 * @argc: size of the argument vector
 * @argv: program name and arguments
 *
 * Return: Always 0
 */
int main(int argc __attribute__ ((unused)), char *argv[])
{
	_puts(argv[0]);

	return (0);
}
