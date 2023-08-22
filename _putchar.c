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
/**
  * store - store a char in the buffer
  * @c: char
  * @noError: flag, if 1 means no keep storing, otherwise stop storing
  *
  * Return: pointer to the buffer
  */
char *store(char c, int noError)
{
	static int i;
	static char buff[bufferSize];

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
/**
  * toScreen - prints the buffer content to the screen
  * @s: pointer to the string ti be printed
  *
  * Return: 1 if success, otherwise 0
  */

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
