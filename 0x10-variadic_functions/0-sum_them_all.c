#include "variadic_functions.h"

/**
 * sum_them_all - compute the sum of a variable number of arguments
 * @n: the number of unnamed arguments
 * @...: the unnamed arguments
 *
 * Return: the sum of the unnamed arguments
 */
int sum_them_all(const unsigned int n, ...)
{
	int sum = 0;
	unsigned int remaining = n;
	va_list ap;

	va_start(ap, n);

	while (remaining--)
		sum += va_arg(ap, int);

	va_end(ap);

	return (sum);
}
