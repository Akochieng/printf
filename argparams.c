#include "main.h"
#include <stdio.h>
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
			_puts(prt, set);
			pos = 0;
		}
	}
	return (pos - 1);
}

int signedint(char *prt, int pos, va_list *ag)
{
	int num;
	size_t res = 0;

	num = va_arg(*ag, int);
	if (num < 0)
	{
		*(prt + pos) = '-';
		res = -1 * num / 10;
		res = (res * 10) + (num % 10);
		pos = pos + 1;
	}
	else
		res = 0 + num;
	return (copysizet(prt, pos, res));
}

int unsignedint(char *prt, int pos, va_list *ag)
{
	size_t res = 0;

	res = va_arg(*ag, unsigned int);
	return (copysizet(prt, pos, res));
}

int copysizet(char *prt, int pos, size_t num)
{
	if (num > 9)
	{
		copysizet(prt, pos + 1, num / 10);
		*(prt + pos) = (num % 10) + '0';
		return (pos + 1);
	}
	*(prt + pos) = num + '0';
	return (pos + 1);
}
