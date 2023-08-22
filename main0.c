#include "main.h"
int main(void)
{
	int size = 0;
	size = _printf("Hi I'm %d years old\nand my bro is %i years old!\n", -24, 023);
	size = _printf("%s\n", NULL);
	_printf("%d\n", size);
	/*_printf("A char: %c, a string: %s, a perc:%% \n", 'B', "Hello");
	_printf("%b\n", 4);
	_printf("%o\n", 87);
	_printf("%x\n", 255);
	_printf("%X\n", 255);
	_printf("%u\n", -1);
	_printf("-------Check the return size-----------\n");
	size = printf("%d\n", 123);
	printf("%d\n", size);
	size = _printf("%d\n", 123);
	_printf("%d\n", size);
	_printf("---------------------------------------\n");

	size = _printf("aa%");
	_printf("%d\n", size);*/
	return (0);
}
