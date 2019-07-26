#include "variadic_functions.h"

/**
 * print_strings - print strings
 * @separator: the output separator
 * @n: the number of strings to print
 * @...: the strings to print
 *
 * Description: This function prints strings, separated by separator, followed
 * by a new line. If separator is NULL, it's treated as the empty string. If a
 * string is NULL, print "(nil)" instead.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int remaining = n;
	const char *s = NULL;
	va_list strings;

	va_start(strings, n);

	if (!separator)
		separator = "";

	while (remaining--)
	{
		s = va_arg(strings, const char *);
		printf("%s%s", s ? s : "(nil)", remaining ? separator : "\n");
	}

	va_end(strings);
}
