#include "main.h"

/**
 * print_oct - a function that prints out octal numbers
 * @args: a list of all the arguments that the function will take
 * @params: the parameters struct
 * Return: The number of characters
 */

int print_oct(va_list args, params_t *params)
{
	unsigned long l;
	char *str;
	int c = 0;

	if (params->l_modifier)
		l = (unsigned long)va_arg(args, unsigned long);

	else if (params->h_modifier)
		l = (unsigned short int)va_arg(args, unsigned int);

	else
		l = (unsigned int)va_arg(args, unsigned int);

	str = convert(l, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && l)
		*--str = '0';

	params->unsign = 1;

	return (c += print_number(str, params));
}
