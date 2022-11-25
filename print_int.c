#include "main.h"

/**
 * print_int - A function that prints out integers
 * @args: a variable print that takes a varrying amount of function arguments
 * @params: the parameters struct
 * Return: Charcter
 */

int print_int(va_list args, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(args, long);

	else if (params->h_modifier)
		l = (short int)va_arg(args, int);

	else
		l = (int)va_arg(args, int);

	return (print_number(convert(l, 10, 0, params), params));
}
