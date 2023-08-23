#include "main.h"
/**
  * pr_binary - prints binary representation of the va_list to the stdout
  * @ap: variadic function parameter
  *
  * Return: Number of chars printed
  */

int pr_binary(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	int arr[32];
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
		store(arr[i--] + '0', 1);
	}
	return (len);
}

/**
  * pr_oct - prints octal representation of the va_list to the stdout
  * @ap: variadic function parameter
  *
  * Return: Number of chars printed
  */

int pr_oct(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	int arr[32];
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
		store(arr[i--] + '0', 1);
	}
	return (len);
}
/**
  * pr_hex - prints hexa representation of the va_list to the stdout
  * @ap: variadic function parameter
  *
  * Return: Number of chars printed
  */

int pr_hex(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	int arr[32];
	int i, len;
	char ch[6] =  "abcdef";

	i = 0;
	while (n)
	{
		arr[i++] = n % 16 > 9 ? (unsigned int) ch[n % 16 - 10] : n % 16;
		n /= 16;
	}
	len = i--;
	while (i > -1)
	{
		if (arr[i] > 9)
			store(arr[i--], 1);
		else
			store(arr[i--] + '0', 1);
	}
	return (len);
}
/**
  * pr_HEX - prints hexa representation in capital of the va_list to the stdout
  * @ap: variadic function parameter
  *
  * Return: Number of chars printed
  */

int pr_HEX(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	int arr[32];
	int i, len;
	char ch[6] =  "ABCDEF";

	i = 0;
	while (n)
	{
		arr[i++] = n % 16 > 9 ? (unsigned int) ch[n % 16 - 10] : n % 16;
		n /= 16;
	}
	len = i--;
	while (i > -1)
	{
		if (arr[i] > 9)
			store(arr[i--], 1);
		else
			store(arr[i--] + '0', 1);
	}
	return (len);
}
