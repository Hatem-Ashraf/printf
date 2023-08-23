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
		store('-', 1), len++;
	while (i > -1)
	{
		store(arr[i--], 1);
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
	char c = (va_arg(ap, int));

	store(c, 1);
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
	char arr[] = "(nil)";
	int len = 0;

	if (!s)
	{
		while (arr[len])
			store(arr[len++], 1);
		return (len);
	}
	while (*s)
		store(*s++, 1), len++;
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
	store('%', 1);
	return (1);
}
