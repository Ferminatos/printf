#include "main.h"
#include <stdlib.h>


int print_x(va_list args)
{
	unsigned int j;
	int i, chars;
	char *hexvalues;
	char *hex;
	
	chars = 0;

	j = va_arg(args, int);
	hexvalues = "0123456789abcdef";
	hex = malloc(9 * sizeof(char));
	
	if (hex == NULL)
		return (chars);
	
	for (i = 0; j != 0; i++)
	{
		hex[i] = hexvalues[j % 16];
		j /= 16;
	}
	
	for (i--; i >= 0; i--)
	{
		_putchar(hex[i]);
		chars++;
	}
	free(hex);
	
	return (chars);
}

int print_X(va_list args)
{
	unsigned int j;
	int i, chars;
	char *hexvalues;
	char *hex;
	
	chars = 0;

	j = va_arg(args, int);
	hexvalues = "0123456789ABCDEF";
	hex = malloc(9 * sizeof(char));

	if (hex == NULL)
		return (chars);

	for (i = 0; j != 0; i++)
	{
		hex[i] = hexvalues[j % 16];
		j /= 16;
	}

	for (i--; i >= 0; i--)
	{
		_putchar(hex[i]);
		chars++;
	}
	free(hex);

	return (chars);
}
