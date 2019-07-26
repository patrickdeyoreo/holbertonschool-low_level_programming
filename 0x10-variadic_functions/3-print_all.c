#include "variadic_functions.h"


/**
 * print_char - print a character
 * @n: the number of characters to print
 * @...: the character(s) to print
 */
int print_char(va_list args)
{
	return printf("%c", va_arg(args, int));
}


/**
 * print_float - print a float
 * @n: the number of floats to print
 * @...: the float(s) to print
 */
int print_float(va_list args)
{
	return printf("%f", va_arg(args, double));
}


/**
 * print_int - print an integer
 * @n: the number of integers to print
 * @...: the integer(s) to print
 */
int print_int(va_list args)
{
	return printf("%i", va_arg(args, int));
}


/**
 * print_str - print a string
 * @n: the number of strings to print
 * @...: the string(s) to print
 */
int print_str(va_list args)
{
	return printf("%s", va_arg(args, const char *));
}


/**
 * get_print_func - get a printf function based on a format spec
 * @spec: the format spec
 */
int (*get_print_func(char spec))(va_list)
{
	struct print_fn funcs[] = {
		{ 'c',  print_char },
		{ 'f',  print_float },
		{ 'i',  print_int },
		{ 's',  print_str },
		{ '\0', NULL }
	};
	unsigned int i = 0;

	while (funcs[i].c)
	{
		if (spec == funcs[i].c)
			return (funcs[i].f);
		++i;
	}

	return (NULL);
}


/**
 * print_all - print anything
 * @format: a format string listing the types of the proceeding arguments
 * @...: the values to print
 */
void print_all(const char * const format, ...)
{
	int (*print_func)(va_list);
	va_list args;
	unsigned int i = 0;

	va_start(args, format);

	while (format[i])
	{
		print_func = get_print_func(format[i]);
		if (print_func)
			print_func(args);
		++i;
	}

	printf("\n");

	va_end(args);
}
