#include "main.h"

/**
 * print_per - a function that accounts for %% as an input
 * @args: argument passed
 * @params: the parameters struct
 * Return: Return the % character
 */

int print_per(va_list args, params_t *params)
{
	(void)args;
	(void)params;

	return (_putchar('%'));
}
