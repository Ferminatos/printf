#include "main.h"

/**
 * check_formatter - Function that checks if the character pointer is NULL, and
 * if it is NULL, it will return the number of charaters which is 0. Verifies
 * if the first character is a "%", if it is, move to the next character,
 * checks the array of structs, if they match, run the function. If not, print
 * the % and the character.
 * @args: a pointer that is initiated by va_list
 * @format: a pointer variable that points to what's being passed to _printf
 * @print_a: The array of structs that is initated in the _printf function
 * Return: The number of characters that was printed
 */

int check_formatter(va_list args, const char *format, print_a_t print_a[])
{
	int formatter, i, j, chars;

	formatter = i = j = chars = 0;

	for (i = 0; format != NULL && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			for (j = 0; j < 7; j++)
			{
				if (print_a[j].s == format[i])
				{
					chars += (print_a[j].f(args));
					formatter = 1;
				}
			}

			if (formatter == 0)
			{
				i--;
				_putchar(format[i]);
				i++;
				_putchar(format[i]);
				chars += 2;
			}
		}

		else
		{
			_putchar(format[i]);
			chars++;
		}
	}

	return (chars);
}
