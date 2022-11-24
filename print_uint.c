#include "main.h"

/**
 * print_int - A function that prints out integers
 * @args: a variable print that takes a varrying amount of function arguments
 * Return: Charcter
 */



int print_uint(va_list args)
{
	unsigned int n;
	int rem, len = 0, chars;

	n = va_arg(args, int);

	while (n != 0)
	{
		len++;
		n /= 10;
	}

	chars = 0;
	
	while (chars < len)
	{
		rem = n % 10;
		n = n / 10;

		str[len - (i + 1)] = rem + '0';
		chars++;
	}

	return (chars);
}
