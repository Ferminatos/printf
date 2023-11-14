#ifndef MAIN_H_
#define MAIN_H_

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define FIELD_BUF_SIZE 50

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters of the printf function structure definition
 *
 * @unsign: flag for unsigned value 
 *
 * @plus_flag: flag for if + specified
 * @space_flag: flag for if ' ' specified
 * @hashtag_flag: flag for if # specified
 * @zero_flag: flag for if 0 specified
 * @minus_flag: flag for if - specified
 *
 * @width: width filed
 * @precision: precision filed
 *
 * @h_modifier: h modifier specified
 * @l_modifier: l modifier specified
 */

typedef struct parameters
{
	unsigned int unsign		: 1;


	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;


	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params_t;

/**
 * struct specifier - A structure definition for specifiers
 * that has a pointer character and a pointer to a function
 * @s: a character pointer
 * @f: a function pointer
 */

typedef struct specifier
{
	char *s;
	int (*f)(va_list, params_t *);

} specifier_t;

void init_params(params_t *params, va_list args);

int (*get_specifier(char *s))(va_list args, params_t *params);

int get_print_func(char *s, va_list args, params_t *params);

int print_from_to(char *start, char *stop, char *except);

int print_char(va_list args, params_t *params);

int print_str(va_list args, params_t *params);

int print_per(va_list args, params_t *params);

char *convert(long int num, int base, int flags, params_t *params);

int print_int(va_list args, params_t *params);

int print_bin(va_list args, params_t *params);

int print_uint(va_list args, params_t *params);

int print_oct(va_list args, params_t *params);

int print_x(va_list args, params_t *params);

int print_X(va_list args, params_t *params);

int print_S(va_list args, params_t *params);

int print_add(va_list args, params_t *params);

int _isdigit(int c);

int _strlen(char *s);

int print_number(char *str, params_t *params);

int print_number_right_shift(char *str, params_t *params);

int print_number_left_shift(char *str, params_t *params);

int check_flag(char *s, params_t *params);

int check_modifier(char *s, params_t *params);

char *get_width(char *s, params_t *params, va_list ap);

void init_params(params_t *params, va_list args);

char *get_precision(char *p, params_t *params, va_list args);

int print_from_to(char *start, char *stop, char *except);

int _putchar(int c);

int _puts(char *str);

int _printf(const char *format, ...);

#endif
