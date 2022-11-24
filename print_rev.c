#include "main.h"

/**
 * print_rev - a function that prints the string in reverse
 * @args: a variable that takes in a varrying amount of function arguments
 * Return: The number of characters
 */

int print_rev(va_list args)
{
	char *s;
	int i, j, chars;

	chars = 0;

	s = va_arg(args, char *);

	for (i = 0; s[i] != '\0'; i++)
		;

	for (j = i - 1; j >= 0; j--)
	{
		_putchar(s[j]);
		chars++;
	}

	return (chars);
}
