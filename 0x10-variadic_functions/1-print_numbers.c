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
	va_list args;
	unsigned int remaining = n;

	va_start(args, n);
	if (!separator)
		separator = "";
	while (remaining--)
	{
		printf("%i", va_arg(args, int));
		if (remaining)
			printf("%s", separator);
	}
	printf("\n");
	va_end(args);
}
