#include "main.h"

/**
 * print_S - custom format specifier
 * @args: argument passed
 * Return: number chars printed
 */

int print_S(va_list args)
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
				sum += _putchar('0');

			sum += _puts(hex);
		}

		else
		{

			sum += _putchar(*str);
		}
	}

	return (sum);
}
