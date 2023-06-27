#include "main.h"
/**
  *copychar - copies a character to the print buffer
  *@prt: the print buffer
  *@pos: the position of the print buffer cursor
  *@ag: the va_list parameter
  *
  *Return: the new pos
  */
int copychar(char *prt, int pos, va_list *ag)
{
	int val;

	val = va_arg(*ag, int);
	*(prt + pos) = val;
	return (pos);
}
/**
  *copystr - copies a string to the print_buffer
  *@prt: the print buffer
  *@pos: the position of the print buffer cursor
  *@ag: the va_list parameter
  *
  *Return: the new pos
  */
int copystr(char *prt, int pos, va_list *ag)
{
	char *thearg;

	thearg = va_arg(*ag, char *);
	while (*thearg != '\0')
	{
		*(prt + pos) = *thearg;
		thearg++;
		pos++;
		if (pos == BUFFERSIZE - 2)
		{
			*(prt + pos) = '\0';
			_puts(prt);
			pos = 0;
		}
	}
	return (pos - 1);
}
