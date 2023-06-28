#include "../main.h"
#include <stdio.h>
#include <limits.h>

/**
  *main - entry point
  *
  *Return: Always 0
  */
int main(void)
{
	unsigned int ui;
/*	int len;

	len = _printf("Let's try to printf a simple sentence.\n");
*/	ui = (unsigned int)INT_MAX + 1024;
/*	_printf("Length:[%d, %i]\n", len, len);
	_printf("Negative:[%d]\n", -762534);
*/	_printf("Unsigned:[%u]\n", ui);
	_printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("%u\n", ui);
	return (0);
}
