#include "main.h"
#include <stdlib.h>

/**
 * print_bin - print binary
 * @args: arguments passed
 * Return: number of characters
 */

int print_bin(va_list args)
{
	unsigned int n;
	int i, chars;
	char *binaryvalues;
	char *binary;

	chars = 0;
	n = va_arg(args, int);
	binaryvalues = "01";
	binary = malloc(33 * sizeof(char));

	if (binary == NULL)
		return (chars);

	if (n == 0)
	{
		_putchar('0');
		chars++;
	}

	else
	{
		for (i = 0; n != 0; i++)
		{
			binary[i] = binaryvalues[n % 2];
			n /= 2;
		}

		for (i--; i >= 0; i--)
		{
			_putchar(binary[i]);
			chars++;
		}

	}
	free(binary);

	return (chars);
}
