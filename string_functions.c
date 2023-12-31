#include "main.h"
#include <unistd.h>
#include <stdio.h>
/**
  *_puts - function to print a string of characters
  *@s: pointer to the memory location storing the string
  *Description: this function acts as the most basic printing
  *function in the printf program. Once all parameters have been parsed
  *and stored in the print_buffer, this function is called to print
  *the contents of the print_buffer
  *Return: the number of characters printed
  */
int _puts(char *s, int action)
{
	static int printed;
	size_t len = 0;

	len = _strlen(s);
	if (len == 0)
	{
		if (action == reset)
			printed = 0;
		return (len);
	}
	printed += write(1, s, len);
	return (printed);
}
/**
  *_strlen - compute the length of a string
  *@s: the string
  *
  *Return: the length of a string
  */
size_t _strlen(char *s)
{
	size_t len = 0;

	if (s == NULL)
		return (len);
	for (len = 0; s[len] != '\0'; len++)
		;
	return (len);
}
