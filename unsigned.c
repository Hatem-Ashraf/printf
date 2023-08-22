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
	char *ad = (char *)va_arg(ap, void *);
/*	char *s = malloc(sizeof(void *) + 1);*/

	if (!ad)
		return (-1);
	/*int i = 0;*/

	printf("%p\n", ad);
/*	while (ad[i])
		store(ad[i++], 1);
		*/
	return (100000);

}
