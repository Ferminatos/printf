#include "main.h"

/**
 * print_char - a funciton that prints out a character
 * @args: a variable that takes in a varrying amount of function arguments
 * Return: Zero is returned
 */

int print_char(va_list args)
{
	char j;

	j = va_arg(args, int);
	_putchar(j);

	return (1);
}
