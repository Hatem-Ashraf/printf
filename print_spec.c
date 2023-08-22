#include "main.h"
/**
  * pr_int - prints integer "%d" or "%i" to the stdout
  * @ap: va_list parameter
  *
  * Return: Number of digits printed
  */
int pr_int(va_list ap)
{
	int n = va_arg(ap, int);
	char arr[15] = {0};
	int i, len, isNeg;

	isNeg = 0;
	i = 0;
	if (n < 0)
	{
		n = ~n + 1;
		isNeg = 1;
	} else if (n == 0)
		arr[i++] = '0';
	while (n)
	{
		arr[i++] = (n % 10) + '0';
		n /= 10;
	}
	len = i--;
	if (isNeg)
		_putchar('-'), len++;
	while (i > -1)
	{
		_putchar(arr[i--]);
	}
	/*len is the number of digits*/
	return (len);
}
/**
  * pr_char - prints a char to the stdout
  * @ap: variadic function parameter
  *
  * Return: Number of chars printed
  */
int pr_char(va_list ap)
{
	_putchar(va_arg(ap, int));
	return (1);
}
/**
  * pr_str - prints a string to the stdout
  * @ap: variadic function parameter
  *
  * Return: Number of chars printed
  */
int pr_str(va_list ap)
{
	char *s = va_arg(ap, char *);
	int len = 0;

	if (!s)
		return (-1);
	while (*s)
		_putchar(*s++), len++;
	return (len);
}
/**
  * pr_perc - prints a % to the stdout
  * @ap: variadic function parameter
  *
  * Return: Number of chars printed
  */

int pr_perc(va_list ap)
{
	(void)ap;
	_putchar('%');
	return (1);
}
