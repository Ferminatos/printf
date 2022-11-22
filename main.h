#ifndef MAIN_H_
#define MAIN_H_

#include <stdarg.h>
#include <stdio.h>

/**
 * struct vtype - struct vtype
 * @tp: tp
 * @f: function
 */

typedef struct vtype
{

	char tp;

	void (*f)();

} vtype_t;

int _printf(const char *format, ...);

void _write_buffer(char *buffer, int *index);

void reset_buffer(char buffer[]);

void format_s(va_list valist, char *buffer, int *index);

void format_c(va_list valist, char *buffer, int *index);

void format_perc(va_list valist, char *buffer, int *index);

#endif
