#include "main.h"                                                                                                                                    

/**
 * print_int - A function that prints out integers
 * @args: A variable that takes in a varrying amount of function arguments
 * Return: The character
 */

int print_int(va_list args)
{
        int n, chars;

        n = va_arg(args, int);
        chars = print_number(n);

        return (chars);
}
