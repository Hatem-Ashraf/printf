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
char *store(char c, int noError)
{
	static int i = 0;
	static char buff[bufferSize] = {'0'};

	if (i >= 1023)
		return (buff);
	if (!noError)
	{
		i = 0;
		return (NULL);
	}
	buff[i] = c;
	i++;
	return (buff);
}
int toScreen(char *s)
{
	int i = 0;

	s = store('\0', 1);
	while (s[i])
	{
		_putchar(s[i++]);
	}
	store('e', 0);
	return (1);

}
