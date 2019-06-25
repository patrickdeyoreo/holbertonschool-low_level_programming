#include "holberton.h"

/**
 * print_last_digit - None
 *
 * Description: None
 * Return: value of the last digit
 */
int print_last_digit(int n)
{
	n = _abs(n % 10);
	_putchar('0' + n);
	return (n);
}
