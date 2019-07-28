#include "variadic_functions.h"


/**
 * print_char - print a character
 * @args: a pointer to the current argument
 *
 * Return: the number of bytes printed
 */
int print_char(va_list args)
{
	return (printf("%c", va_arg(args, int)));
}


/**
 * print_float - print a float
 * @args: a pointer to the current argument
 *
 * Return: the number of bytes printed
 */
int print_float(va_list args)
{
	return (printf("%f", va_arg(args, double)));
}


/**
 * print_int - print an integer
 * @args: a pointer to the current argument
 *
 * Return: the number of bytes printed
 */
int print_int(va_list args)
{
	return (printf("%i", va_arg(args, int)));
}


/**
 * print_str - print a string
 * @args: a pointer to the current argument
 *
 * Return: the number of bytes printed
 */
int print_str(va_list args)
{
	return (printf("%s", va_arg(args, const char *)));
}


/**
 * print_all - print anything
 * @format: a format string listing the types of the proceeding arguments
 * @...: the values to print
 */
void print_all(const char * const format, ...)
{
	va_list args;
	struct print_fn funcs[] = {
		{ 'c',  print_char },
		{ 'f',  print_float },
		{ 'i',  print_int },
		{ 's',  print_str },
		{ '\0', NULL }
	};
	unsigned int fn_index, arg_index;

	va_start(args, format);

	arg_index = 0;
	while (format[arg_index])
	{
		fn_index = 0;
		while (funcs[fn_index].spec)
		{
			if (format[arg_index] == funcs[fn_index].spec)
				funcs[fn_index].func(args);
			++fn_index;
		}
		++arg_index;
	}
	printf("\n");

	va_end(args);
}
