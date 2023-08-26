#include "main.h"
/**
  * check - checks for the corner cases before printing
  * @form: format, the string that passes to the printf
  *
  * Return: 1 on success, otherwise 0
  */
int check(const char *form)
{
	int i, j;
	int out = 1;
	st_spec specArr[] = {
		{"c", pr_char}, {"s", pr_str}, {"i", pr_int}, {"d", pr_int},
		{"b", pr_binary}, {"o", pr_oct}, {"x", pr_hex}, {"X", pr_HEX},
		{"u", pr_unsign}, {"p", pr_address}, {"%", pr_perc}, {"S", pr_unprintable},
		{"R", pr_ROT13}, {NULL, NULL}
	};

	if (!form)
		return (0);
	i = 0;
	while (form[i])
	{
		if (form[i] == '%')
		{
			j = 0;
			while (specArr[j].s)
			{
				if (!form[i + 1] || form[i + 1] == ' ')
					return (0);
				if (form[i + 1] == *(specArr[j].s))
				{
					out = 0;
					i++;
					break;
				}
				j++;
			}
			if (out)
				return (0);
		}
		i++;
	}
	return (1);
}
/**
  * _printf - like the printf in the stdio.h
  * @format: string that contains flag, width, ...
  *
  * Return: the number of characters printed, otherwise -ve number
  */
int _printf(const char *format, ...)
{
	int i, j, printSize, temp;
	st_spec specArr[] = {
		{"c", pr_char}, {"s", pr_str}, {"i", pr_int}, {"d", pr_int},
		{"b", pr_binary}, {"o", pr_oct}, {"x", pr_hex}, {"X", pr_HEX},
		{"u", pr_unsign}, {"p", pr_address}, {"%", pr_perc}, {"S", pr_unprintable},
		{"R", pr_ROT13}, {NULL, NULL}
	};
	va_list ap;

	va_start(ap, format);
	printSize = 0;
	if (!check(format))
		return (-1);
	/*Initialize the static i in the store to be 0*/
	store('n', 0);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; specArr[j].s; j++)
				if (format[i + 1] == *(specArr[j].s))
				{
					temp = specArr[j].f(ap);
					i++;
					if (temp <= 0)
					{
						store('e', 0);
						return (-1);
					}
					printSize += temp;
					break;
				}
		} else
		{
			store(format[i], 1);
			printSize++;
		}
	}
	toScreen(store('\0', 1));
	return (printSize);
}
