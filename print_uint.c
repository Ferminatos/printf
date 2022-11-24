#include "main.h"
#include <stdlib.h>

/**
 * print_uint - A function that prints out unsigned integers
 * @args: a variable print that takes a varrying amount of function arguments
 * Return: The number of characters
 */

int print_uint(va_list args)
{
	unsigned int i;
	int j, chars, numlen;
	char *num;

	chars = 0;

	i = va_arg(args, int);
	numlen = num_len(i);
	num = malloc(numlen * sizeof(char));

	if (num == NULL)
		return (chars);

	utos(num, i);

	for (i = chars, j = 0; j < numlen; chars += 1, i++, j++)
	{
		if (chars == 1024)
		{
			chars = 0;
		}
		_putchar(num[j]);
	}
	free(num);

	return (chars);
}

/**
 * utos - uint to string
 * @str: string
 * @num: num
 * Return: char array
 */

char *utos(char str[], unsigned int num)
{
	int i, rem, len = 0, n;

	n = num;

	while (n != 0)
	{
		len++;
		n /= 10;
	}

	i = 0;

	while (i < len)
	{
		rem = num % 10;
		num = num / 10;
		str[len - (i + 1)] = rem + '0';
		i++;
	}
	str[len] = '\0';

	return (str);

}

/**
 * num_len - getting the length of a number
 * @num: the number
 * Return: int
 */

int num_len(int num)
{
	int n, len;

	n = num;
	len = 0;

	while (n != 0)
	{
		len++;
		n /= 10;
	}

	return (len);
}
