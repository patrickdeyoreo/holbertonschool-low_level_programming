#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * struct printf_fn - a format spec associated with a printf function
 * @c: the format spec
 * @f: the print function
 */
struct print_fn
{
	char c;
	int (*f)(va_list);
};


int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif /* VARIADIC_FUNCTIONS_H */
