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
	int arr[20] = {0};
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
	void *ad = va_arg(ap, void *);
	(void)ad;
	(void)ap;
	return (0);

}
