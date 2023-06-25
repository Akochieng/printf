#include "main.h"
/**
  *mem_set - sets the memory to 0
  *@s: pointer to the memory location
  *@size: the size of the memory
  *Description: this function ensures that data that was previously
  *stored in the memory location is not printed out. It is more of
  *a safety precaution in the program.
  *Return: void
  */
void mem_set(char *s, int size)
{
	int counter;

	for (counter = 0; counter < size; counter++)
		s[counter] = 0;
}
