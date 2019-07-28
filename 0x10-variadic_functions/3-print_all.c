#include "variadic_functions.h"


/**
 * print_char - print a character
 * @args: the va_list with the character to print as it's next element
 *
 * Return: the number of bytes printed
 */
void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}


/**
 * print_float - print a float
 * @args: the va_list with the float to print as it's next element
 *
 * Return: the number of bytes printed
 */
void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}


/**
 * print_int - print an integer
 * @args: the va_list with the integer to print as it's next element
 *
 * Return: the number of bytes printed
 */
void print_int(va_list args)
{
	printf("%i", va_arg(args, int));
}


/**
 * print_str - print a string
 * @args: the va_list with the string to print as it's next element
 */
void print_str(va_list args)
{
	const char *str = va_arg(args, const char *);
	printf("%s", str ? str : "(nil)");
}


/**
 * print_all - print anything
 * @format: a format string listing the types of the proceeding arguments
 * @...: the values to print
 */
void print_all(const char * const format, ...)
{
	va_list args;
	print_fn_t fn_list[] = {
		{ 'c',  print_char },
		{ 'f',  print_float },
		{ 'i',  print_int },
		{ 's',  print_str },
		{ '\0', NULL }
	};
	unsigned int fn_index, format_index = 0;

	va_start(args, format);
	while (format[format_index])
	{
		fn_index = 0;
		while (fn_list[fn_index].format)
		{
			if (format[format_index] == fn_list[fn_index].format)
				fn_list[fn_index].fn(args);
			++fn_index;
		}
		++format_index;
	}
	printf("\n");
	va_end(args);
}
