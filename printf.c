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
	char *print_buffer;
	int printed, state;
	va_list args;

	printed = state = 0;
	if (format == NULL)
		return (0);
	print_buffer = malloc(BUFFERSIZE);
	if (print_buffer == NULL)
	{
		_puts("Cannot allocate memory\n");
		exit(12);
	}
	va_start(args, format);
	mem_set(print_buffer, BUFFERSIZE);
	state = _getchar(format, print_buffer, args, &printed);
	if (state == -1)
	{
		_puts("Function not implemented\n");
		exit(38);
	}
	printed += _puts(print_buffer);
	free(print_buffer);
	va_end(args);
	return (printed);
}
/**
  *_getchar - parses that program's input parameters in preparation for
  *printing
  *@format: the last parameter before the va_list args
  *@print_buffer: buffer used to store characters before printing
  *@args: va_list args used to store the input parameters
  *@printed: pointer to variable used to store the number of printed characters
  *
  *Return: -1 on failure, 0 otherwise
  */
int _getchar(const char *format, char *print_buffer, va_list args __attribute__((unused)), int *printed)
{
	static int pos;

	while (*format != '\0')
	{
		if (pos == BUFFERSIZE - 1)
		{
			print_buffer[pos] = '\0';
			*printed += _puts(print_buffer);
			pos = 0;
		}
		switch (*format)
		{
			case ('%'):
				break;
			default:
				print_buffer[pos] = *format;
				break;
		}
		pos++;
		format++;
	}
	print_buffer[pos] = '\0';
	return (0);
}
