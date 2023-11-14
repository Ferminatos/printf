#include "main.h"

/**
 * print_bin - print binary
 * @args: arguments passed
 * @params: the parameters struct
 * Return: number of characters
 */

int print_bin(va_list args, params_t *params)
{
	unsigned int n = va_arg(args, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->hashtag_flag && n)
		*--str = '0';

	params->unsign = 1;

	return (c += print_number(str, params));
}
