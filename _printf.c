#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - the clone printf function
 * @format: Detects what format the arguments comes in
 * Return: The number of characters to be printed
 */

int _printf(const char *format, ...)
{
	int sum = 0;
	va_list args;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, args);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (check_flag(p, &params))
		{
			p++;
		}
		p = get_width(p, &params, args);
		p = get_precision(p, &params, args);
		if (check_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			sum += print_from_to(start, p,
					params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			sum += get_print_func(p, args, &params);

	}
	_putchar(BUF_FLUSH);
	va_end(args);

	return (sum);
}

/**
 * get_print_func - finds the format func
 * @s: the format string
 * @args: list argument pointer
 * @params: the parameters struct
 * Return: the number of bytes printed
 */

int get_print_func(char *s, va_list args, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(args, params));

	return (0);
}

/**
 * check_flag - check for flag
 * @str: the format string
 * @params: the parameters struct
 * Return: if flag was valid or not
 */

int check_flag(char *str, params_t *params)
{
	int i = 0;

	switch (*str)
	{
	case '+':
		i = params->plus_flag = 1;
		break;

	case ' ':
		i = params->space_flag = 1;
		break;

	case '#':
		i = params->hashtag_flag = 1;
		break;

	case '-':
		i = params->minus_flag = 1;
		break;

	case '0':
		i = params->zero_flag = 1;
		break;

	}

	return (i);
}

/**
 * check_modifier - checks for modifier
 * @str: the format string
 * @params: the parameters struct
 * Return: if modifier was valid or not
 */

int check_modifier(char *str, params_t *params)
{
	int i = 0;

	switch (*str)
	{
	case 'h':
		i = params->h_modifier = 1;
		break;
	case 'l':
		i = params->l_modifier = 1;
		break;
	}

	return (i);
}
/**
 * print_from_to - prints a range of char addresses
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 * Return: number bytes printed
 */

int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);

		start++;
	}

	return (sum);
}
