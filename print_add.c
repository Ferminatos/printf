#include "main.h"
#include <stdlib.h>

/**
 * print_add - print a memory address
 * @args: argument passed
 * @params: the parameters struct
 * Return: number of characters
 */

int print_add(va_list args, params_t *params)
{
	unsigned long int n = va_arg(args, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';

	return (print_number(str, params));
}
