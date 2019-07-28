#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * struct print_fn - a format spec associated with a print function
 * @format: the format specifier
 * @fn: the print function
 *
 * Description:
 */
typedef struct print_fn
{
	char format;
	void (*fn)(va_list);
} print_fn_t;


int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);
void print_char(va_list args);
void print_float(va_list args);
void print_int(va_list args);
void print_str(va_list args);

#endif /* VARIADIC_FUNCTIONS_H */
