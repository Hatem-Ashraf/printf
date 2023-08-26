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

/**
  * pr_unprintable - prints unprintable chars
  * @ap: va_list param
  *
  * Return: length of the chars printed
  */
int pr_unprintable(va_list ap)
{
	char *str = va_arg(ap, char *);
	int i, j, len, n;
	int temp[10];
	char ch[6] = "ABCDEF";
	char nil[] = "(nil)";

	len = 4;
	if (!str)
	{
		while (nil[len])
			store(nil[len++], 1);
		return (len);
	}
	for (i = 0; str[i]; i++)
	{
		if ((str[i] > 0 && str[i] < 32) || (str[i] >= 127))
		{
			n = str[i];
			for (j = 0; n; j++)
			{
				temp[j] = n % 16 > 9 ? ch[n % 16 - 10] : n % 16;
				n /= 16;
			}
			store('\\', 1);
			store('x', 1);
			if (--j < 1)
			{
				store('0', 1);
				store(temp[0] > 9 ? temp[0] : temp[0] + '0', 1);
			} else
			{
				store(temp[1] > 9 ? temp[1] : temp[1] + '0', 1);
				store(temp[0] > 9 ? temp[0] : temp[0] + '0', 1);
			}
			continue;
		}
			store(str[i], 1);
			len++;
	}
	return (len);
}

/**
  * pr_ROT13 - converts string into ROT13
  * @ap: va_list param
  *
  * Return: length of the chars
  */
int pr_ROT13(va_list ap)
{
	int i;
	char *str = va_arg(ap, char *);

	for (i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			store((((str[i] - 'a') + 13) % 26) + 'a', 1);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			store((((str[i] - 'A') + 13) % 26) + 'A', 1);
		else
			store(str[i], 1);
	}
	return (i);
}
