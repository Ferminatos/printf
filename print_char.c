#include "main.h"

/**
 * print_char - a funciton that prints out a character
 * @args: a variable that takes in a varrying amount of function arguments
 * @params: the parameters struct
 * Return: Zero is returned
 */

int print_char(va_list args, params_t *params)
{
	char pad_char = ' ';

	unsigned int pad = 1, chars = 0, ch = va_arg(args, int);

	if (params->minus_flag)
		chars += _putchar(ch);

	while (pad++ < params->width)
		chars += _putchar(pad_char);

	if (!params->minus_flag)
		chars += _putchar(ch);

	return (chars);
}
