#ifndef MAIN_H_
#define MAIN_H_

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define FIELD_BUF_SIZE 50

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specifies
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

int _printf(const char *format, ...);

int _putchar(char c);

int print_int(va_list args, params_t *params);

int print_str(va_list args, params_t *params);

int print_char(va_list args, params_t *params);

int print_number(int n);

int print_per(va_list args, params_t *params);

int print_bin(va_list args, params_t *params);

void a_struct(void);

int print_uint(va_list args, params_t *params);

int print_oct(va_list args, params_t *params);

int print_x(va_list args, params_t *params);

int print_X(va_list args, params_t *params);

int print_S(va_list args, params_t *params);

int print_add(va_list args, params_t *params);

int check_flag(char *s, params_t *params)

int print_rev(va_list args);

int print_R(va_list args);

#endif
