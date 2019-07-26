#include "variadic_functions.h"

/**
 * print_numbers - print integers
 * @separator: the output separator
 * @n: the number of integers to print
 * @...: the integers to print
 *
 * Description: This function prints integers, separated by separator, followed
 * by a new line. If separator is NULL, it's treated as the empty string.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int remaining = n;
	va_list ap;

	va_start(ap, n);

	if (!separator)
		separator = "";

	while (remaining--)
		printf("%i%s", va_arg(ap, int), remaining ? separator : "\n");

	va_end(ap);
}
