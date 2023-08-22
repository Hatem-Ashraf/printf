#include "main.h"
/**
  * _putchar - prints a char to the stdout
  * @c: char
  *
  * Return: On success 1, otherwise 0
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
