#include "main.h"
/**
  *pram - function pointer to select the right function
  *@fmt: the specifier
  *
  *Return: NULL or pointer to the function
  */
int (*pram(char fmt))(char *, int, va_list *)
{
	int i;

	form arglist[] = {
		{'c', copychar},
		{'s', copystr},
		{'u', unsignedint},
		{'\0', NULL}
	};
	for (i = 0; arglist[i].spec != '\0'; i++)
		if (arglist[i].spec == fmt)
			return (arglist[i].f);
	return (NULL);
}
