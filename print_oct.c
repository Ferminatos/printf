#include "main.h"
#include <stdlib.h>

/**
 * print_oct - a function that prints out octal numbers
 * @args: a list of all the arguments that the function will take
 * Return: The number of characters
 */

int print_oct(va_list args)
{
	unsigned int j;
	int i, chars;
	char *octvalues;
	char *oct;


	chars = 0;

	j = va_arg(args, int);
	octvalues = "0123456789ABCDEF";
	oct = malloc(12 * sizeof(char));

	if (oct == NULL)
		return (chars);

	for (i = 0; j != 0; i++)
	{
		oct[i] = octvalues[j % 8];
		j /= 8;
	}

	for (i--; i >= 0; i--)
	{

		_putchar(oct[i]);
		chars++;
	}
	free(oct);

	return (chars);
}
