#include "main.h"

/**
 * print_x - prints hexdecimal in lowercase
 * @args: argument passed
 * @params: the parameters struct
 * Return: number of characters
 */

int print_x(va_list args, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(args, unsigned long);

	else if (params->h_modifier)
		l = (unsigned short int)va_arg(args, unsigned int);

	else
		l = (unsigned int)va_arg(args, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);

	if (params->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';

	}
	params->unsign = 1;

	return (c += print_number(str, params));
}

/**
 * print_X - prints hexdecimal in uppercase
 * @args: argument passed
 * @params: the parameters struct
 * Return: number of characters
 */

int print_X(va_list args, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(args, unsigned long);

	else if (params->h_modifier)
		l = (unsigned short int)va_arg(args, unsigned int);

	else
		l = (unsigned int)va_arg(args, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;

	return (c += print_number(str, params));
}
