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
 * init_params - clears struct fields and reset
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

	params->l_modifier = 0;

	(void)args;
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
