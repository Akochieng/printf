#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#define BUFFERSIZE 1024
/**
  *form: typedef for the struct format
  *struct format - stores the format specifier and associated function
  *@spec: the format specifier
  *@f: the associated function
  */

typedef struct form
{
	char spec;
	int (*f)(char *, int, va_list *);
} form;

int _puts(char *s);
size_t _strlen(char *s);
int _customstrcat(char *src, char *dest, int pos);

int copychar(char *prt, int pos, va_list *ag);
int copystr(char *prt, int pos, va_list *ag);

void mem_set(char *s, int size);

int _printf(const char *format, ...);
int _getchar(const char *format, char *print_buffer, va_list *args);

int (*pram(char fmt))(char *, int, va_list *);
#endif
