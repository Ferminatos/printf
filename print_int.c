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

/**
 * print_uint - A function that prints out unsigned integers
 * @args: a variable print that takes a varrying amount of function arguments
 * @params: the parameters struct
 * Return: The number of characters
 */

int print_uint(va_list args, params_t *params)
{
	unsigned long l;

	if (params->l_modifier)
		l = (unsigned long)va_arg(args, unsigned long);

	else if (params->h_modifier)
		l = (unsigned short int)va_arg(args, unsigned int);

	else
		l = (unsigned int)va_arg(args, unsigned int);

	params->unsign = 1;

	return (print_number(convert(l, 10, CONVERT_UNSIGNED, params), params));
}
