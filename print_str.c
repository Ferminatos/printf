#include "main.h"

/**
 * print_str - a function that prints out a string
 * @args: arguments passed
 * @params: the parameters struct
 * Return: The number of characters
 */

int print_str(va_list args, params_t *params)
{
	char *str = va_arg(args, char *), pad_char = ' ';
	unsigned int pad = 0, chars = 0, i = 0, j;


	(void)params;
	switch ((int)(!str))
	case 1:
		str = NULL_STRING;

		j = pad = _strlen(str);
		if (params->precision < pad)
			j = pad = params->precision;

		if (params->minus_flag)
		{
			if (params->precision != UINT_MAX)
				for (i = 0; i < pad; i++)
					chars += _putchar(*str++);

			else
				chars += _puts(str);
		}

		while (j++ < params->width)
			chars += _putchar(pad_char);

		if (!params->minus_flag)
		{
			if (params->precision != UINT_MAX)
				for (i = 0; i < pad; i++)
					chars += _putchar(*str++);
			else
				chars += _puts(str);
		}

		return (chars);
}

/**
 * print_S - custom string format specifier
 * @args: argument passed
 * @params: the parameters struct
 * Return: number chars printed
 */

int print_S(va_list args, params_t *params)
{
	char *str = va_arg(args, char *);
	char *hex;

	int chars = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));

	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			chars += _putchar('\\');
			chars += _putchar('x');
			hex = convert(*str, 16, 0, params);

			if (!hex[1])
				chars += _putchar('0');
			chars += _puts(hex);
		}

		else
			chars += _putchar(*str);

	}
	return (chars);
}
