#include "main.h"
/**
  * pr_binary - prints binary representation of the va_list to the stdout
  * @ap: variadic function parameter
  *
  * Retrun: Number of chars printed
  */

int pr_binary(va_list ap)
{
	int n = va_arg(ap, int);
	int *arr = malloc(20 * sizeof(int));
	int i, len;

	i = 0;
	while (n)
	{
		arr[i++] = n % 2;
		n /= 2;
	}
	len = i--;
	while (i > -1)
	{
		_putchar(arr[i--] + '0');
	}
	free(arr);
	return (len);
}

/**
  * pr_oct - prints octal representation of the va_list to the stdout
  * @ap: variadic function parameter
  *
  * Retrun: Number of chars printed
  */

int pr_oct(va_list ap)
{
	int n = va_arg(ap, int);
	int arr[20] = {0};
	int i, len;

	i = 0;
	while (n)
	{
		arr[i++] = n % 8;
		n /= 8;
	}
	len = i--;
	while (i > -1)
	{
		_putchar(arr[i--] + '0');
	}
	return (len);
}
/**
  * pr_hex - prints hexa representation of the va_list to the stdout
  * @ap: variadic function parameter
  *
  * Retrun: Number of chars printed
  */

int pr_hex(va_list ap)
{
	int n = va_arg(ap, int);
	int arr[20] = {0};
	int i, len;
	char ch[6]=  "abcdef";

	i = 0;
	while (n)
	{
		arr[i++] = n % 16 > 9 ? ch[n % 16 - 10] : n % 16;
		n /= 16;
	}
	len = i--;
	while (i > -1)
	{
		if (arr[i] >= ch[0] || arr[i] <= arr[5])
			_putchar(arr[i--]);
		else
			_putchar(arr[i--] + '0');
	}
	return (len);
}
int pr_HEX(va_list ap)
{
	int n = va_arg(ap, int);
	int arr[20] = {0};
	int i, len;
	char ch[6]=  "ABCDEF";

	i = 0;
	while (n)
	{
		arr[i++] = n % 16 > 9 ? ch[n % 16 - 10] : n % 16;
		n /= 16;
	}
	len = i--;
	while (i > -1)
	{
		if (arr[i] >= ch[0] || arr[i] <= arr[5])
			_putchar(arr[i--]);
		else
			_putchar(arr[i--] + '0');
	}
	return (len);
}
