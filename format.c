#include "main.h"


int (*formatit(char c))(va_list args)
{
	int i;
	form specs[] = {
	{'c', _putchar},
	{'s', _puts},
	{'d', printint},
	{'i', printint},
	{'b', printb},
	{'u', printu},
	{'o', printo},
	{'x', printx},
	{'X', printX},
	{'S', printS},
	{'p', printp},
	{'%', printperc},
	{ '\0', NULL}
	}

	for (i = 0; specs[i].spec != '\0'; i++)
		if (specs[i].spec == c)
			return (specs[i].f(va_list args));
}
