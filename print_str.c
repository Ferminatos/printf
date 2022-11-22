#include "main.h"

/**
 * print_str - a function that prints out a string
 * @args: a list of all the arguments that the function will take
 * Return: The number of characters
 */

int print_str(va_list args)
{
	char *j;
	int i, chars;

	chars = 0;

	j = va_arg(args, char *);

	if (j == NULL)
		j = "(null)";

	i = 0;

	while (j[i] != '\0')
	{
		_putchar(j[i]);
		i++;
		chars++;
	}

	return (chars);
}
