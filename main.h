#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>

/**
  * struct specifier - Used to map between the char and the func
  * @s: char like 'i, x, c ....'
  * @f: The corresponding function
  */
typedef struct specifier
{
	char *s;
	int (*f)(va_list);
} st_spec;

int _printf(const char *format, ...);

int _putchar(char);

int pr_int(va_list);

#endif
