#include "main.h"
/**
  *_printf - this function serves as the entry point to the printf program
  *@format: the string to be printed
  *Description: variadic function that takes in an unlimited number of
  *parameters with format specifiers
  *Return: number of characters printed
  */
int _printf(const char *format, ...)
{
	char *print;
	int printed, state;
	va_list args;

	printed = state = 0;
	if (format == NULL)
		return (0);
	print = malloc(BUFFERSIZE);
	if (print == NULL)
	{
		_puts("Cannot allocate memory\n", reset);
		exit(12);
	}
	va_start(args, format);
	mem_set(print, BUFFERSIZE);
	state = _getchar(format, print, &args);
	if (state == -1)
		return (-1);
	printed = _puts(print, set);
	_puts(NULL, reset);
	mem_set(print, BUFFERSIZE);
	free(print);
	va_end(args);
	return (printed);
}
/**
  *_getchar - parses that program's input parameters in preparation for
  *printing
  *@format: the last parameter before the va_list args
  *@print: buffer used to store characters before printing
  *@args: va_list args used to store the input parameters
  *
  *Return: -1 on failure, 0 otherwise
  */
int _getchar(const char *format, char *print, va_list *args)
{
	int pos = 0;

	while (*format != '\0')
	{
		if (pos == BUFFERSIZE - 2)
		{
			print[pos] = '\0';
			_puts(print, set);
			pos = 0;
		}
		switch (*format)
		{
			case ('%'):
				if (*(++format) == '%')
					print[pos] = *format;
				else
				{
					pos = pram(*format)(print, pos, args);
					if (pos == -1)
						return (-1);
				}
				break;
			default:
				print[pos] = *format;
				break;
		}
		pos++;
		format++;
	}
	print[pos] = '\0';
	return (0);
}
