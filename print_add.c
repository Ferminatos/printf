#include "main.h"
#include <stdlib.h>

/**
 * print_add - print a memory address
 * @args: argument passed
 * Return: number of characters
 */

int print_add(va_list args)
{
	unsigned long int j;
	int i, chars;
	char *hexvalues;
	char *hex;
	void *a;
	char *b;

	chars = 0;
	a = va_arg(args, void *);
	b = "(nil)";

	if (a == NULL)
	{
		for (i = 0; i < 5; i++, chars += 1)
			_putchar(b[i]);
		return (chars);
	}
	j = (unsigned long int)a;
	hexvalues = "0123456789abcdef";
	hex = malloc(14 * sizeof(char));

	if (hex == NULL)
		return (chars);
	for (i = 0; j != 0; i++)
	{
		hex[i] = hexvalues[j % 16];
		j /= 16;
	}
	i += 2;
	hex[13] = '0';
	hex[12] = 'x';
	for (i--; i >= 0; i--)
	{
		_putchar(hex[i]);
		chars++;
	}
	free(hex);

	return (chars);
}
