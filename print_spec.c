#include "main.h"
/**
  * pr_int - prints integer to the stdout
  * @ap: va_list parameter
  *
  * Return: Number of digits printed
  */
int pr_int(va_list ap)
{
	int n = va_arg(ap, int);
	int arr[15] = {0};
	int i, len;

	i = 0;
	while (n)
	{
		arr[i++] = n % 10;
		n /= 10;
	}
	len = --i;
	while (i > -1)
	{
		_putchar(arr[i--] + '0');
	}
	/*len is the number of digits*/
	return (len);
}
