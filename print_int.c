#include "main.h"

/**
 * print_int - A function that prints out integers
 * @args: a variable print that takes a varrying amount of function arguments
 * Return: Charcter
 */

int print_int(va_list args)
{
	int n, chars;

	n = va_arg(args, int);
	chars = print_number(n);

	return (chars);
}

/**
 * print_number - A function that prints out numbers
 * @n: Number to print
 * Return: Num
 */

int print_number(int n)
{
	int sign, ten, chars;

	chars = 0;
	sign = 1;
	ten = 1000000000;

	if (n > 0)
	{
		n = n * -1;
		sign = sign * -1;
	}

	if (n != 0)
	{
		while (n / ten == 0)
		{
			ten = ten / 10;
		}
		if (sign == 1)
		{
			_putchar('-');
			chars++;
		}
		while (ten >= 1)
		{
			_putchar(-(n / ten) + '0');
			chars++;
			n = n % ten;
			ten = ten / 10;
		}
	}

	else
	{
		_putchar('0');
		chars++;
	}

	return (chars);
}
