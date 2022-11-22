#include "main.h"

/**
 * _printf - Remaking the printf function in the standard input output library
 * @format: Detects what format the arguments come in as
 * Return: The number of characters to be printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int chars;

	print_a_t print_a[] = {
		{'s', print_str},
		{'c', print_char},
		{'%', print_per},
	};

	va_start(args, format);
	chars = 0;

	if (format == NULL || args == NULL)
		return (chars);

	chars = check_formatter(args, format, print_a);
	va_end(args);

	return (chars);
}
