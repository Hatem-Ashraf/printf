#ifndef MAIN_H
#define MAIN_H

#define bufferSize 1024

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

int check(const char *form);

int _putchar(char);

char *store(char, int);

int toScreen(char *);

int pr_int(va_list);

int pr_char(va_list);

int pr_str(va_list);

int pr_perc(va_list);

int pr_binary(va_list);

int pr_oct(va_list);

int pr_hex(va_list);

int pr_HEX(va_list);

int pr_unsign(va_list);

int pr_address(va_list);

int pr_unprintable(va_list);

#endif
