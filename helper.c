#include "main.h"

/**
 * get_specifier - finds the format func
 * @s: the format string
 * Return: the number of bytes printed
 */

int (*get_specifier(char *s))(va_list args, params_t *params)
{
	specifier_t specifiers[] = {
			{"c", print_char},
			{"d", print_int},
			{"i", print_int},
			{"s", print_str},
			{"%", print_per},
			{"b", print_bin},
			{"o", print_oct},
			{"u", print_uint},
			{"x", print_x},
			{"X", print_X},
			{"p", print_add},
			{"S", print_S},
			{"r", print_rev},
			{"R", print_R},
			{NULL, NULL}

	};

	int i = 0;

	while (specifiers[i].s)
	{
		if (*s == specifiers[i].s[0])
			return (specifiers[i].f);
		i++;
	}

	return (NULL);
}

/**
 * init_params - clears struct fields and reset value
 * @params: the parameters struct
 * @args: the argument passed
 * Return: void
 */

void init_params(params_t *params, va_list args)
{
	params->unsign = 0;

	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->h_modifier = 0;
	params->l_modifier = 0;

	(void)args;
}

/**
 * get_precision - gets the precision from the format string
 * @p: the format string
 * @params: the parameters struct
 * @args: the argument passed
 * Return: new pointer
 */

char *get_precision(char *p, params_t *params, va_list args)
{
		int n = 0;

		if (*p != '.')
			return (p);

		p++;

		if (*p == '*')
		{
			n = va_arg(args, int);
			p++;

		}

		else
		{
			while (_isdigit(*p))
				n = n * 10 + (*p++ - '0');

		}
		params->precision = n;

	return (p);
}

/**
 * get_width - gets the width from the format string
 * @str: the format string
 * @params: the parameters struct
 * @args: argument passed
 * Return: new pointer
 */

char *get_width(char *str, params_t *params, va_list args)
{
	int i = 0;

	if (*str == '*')
	{
		i = va_arg(args, int);
		str++;
	}

	else
	{
		while (_isdigit(*str))
			i = i * 10 + (*str++ - '0');
	}
	params->width = i;

	return (str);
}

/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * @params: paramater struct
 * Return: string
 */

char *convert(long int num, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}

	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;

	} while (n != 0);


	if (sign)
		*--ptr = sign;

	return (ptr);

}
