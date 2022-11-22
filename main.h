#ifndef MAIN_H_
#define MAIN_H_

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * struct print_a - A struct that has a pointer character and a pointer
 * to a function
 * @s: a character pointer
 * @f: a function pointer
 */

typedef struct print_a
{
	char s;
	int (*f)();

} print_a_t;

int check_formatter(va_list args, const char *format, print_a_t print_a[]);

int _printf(const char *format, ...);

int _putchar(char c);

int print_str(va_list args);

int print_char(va_list args);

void a_struct(void);

int print_per(int p);
#endif
