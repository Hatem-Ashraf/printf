#include "main.h"
/**
  * pr_unsign - prints unsigned int to the stdout
  * @ap: va_list param
  *
  * Return: No. of chars printed
  */
int pr_unsign(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	int i = 0;
	unsigned int arr[32];
	int len;

	while (n)
	{
		arr[i++] = n % 10;
		n /= 10;
	}
	len = --i;
	while (i > -1)
	{
		store(arr[i--] + '0', 1);
	}
	return (len);
}
/**
  * pr_address - prints address to the stdout
  * @ap: va_list param
  *
  * Return: No. of chars printed
  */
int pr_address(va_list ap)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	int arr[32];
	int i, len;
	char ch[6] =  "abcdef";
	char nul[] = "(null)";

	if (!n)
	{
		len = 0;
		while (nul[len])
			store(nul[len++], 1);
		return (len);
	}
	i = 0;
	while (n)
	{
		arr[i++] = n % 16 > 9 ? (unsigned int) ch[n % 16 - 10] : n % 16;
		n /= 16;
	}
	arr[i++] = 'x';
	arr[i] = '0';
	len = i + 1;
	while (i > -1)
	{
		if (arr[i] > 9)
			store(arr[i--], 1);
		else
			store(arr[i--] + '0', 1);
	}
	return (len);
}
