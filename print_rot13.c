#include "main.h"

/**
 * print_R - prints the rot13'ed string
 * @args: argument passed
 * @params: the parameters struct
 * Return: number of string
 */

int print_R(va_list args, params_t *params)
{
	char *s;
	int i, j, chars;

	char *s1 = "abcdefghijklmABCDEFGHIJKLM ,?!;'@-=+\"\\$%^&*()`~<>/:[]{}_|.\n";
	char *s2 = "nopqrstuvwxyzNOPQRSTUVWXYZ ,?!;'@-=+\"\\$%^&*()`~<>/:[]{}_|.\n";

	chars = 0;
	s = va_arg(args, char *);
	(void)params;

	for (i = 0; s[i] != '\0'; i++, chars += 1)
	{
		for (j = 0; s1[j] != '\0'; j++)
		{
			if (s[i] == s1[j])
			{
				_putchar(s2[j]);
			}

			else if (s[i] == s2[j])
			{
				_putchar(s1[j]);
			}
		}
	}

	return (chars);
}
