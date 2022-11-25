#include "main.h"

/**
 * print_per - a function that accounts for %% as an input
 * @args: argument passed
 * Return: Return the % character
 */

int print_per(va_list args)
{
	(void)args;

	return (_putchar('%'));
}
