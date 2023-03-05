#include "header.h"

/**
 * freeMem - free dynamically allocated memory.
 *
 * p: pointer to memory space.
 * Return: void.
 */
void freeMem(char **p)
{
	int i = 0;

	while (p[i])
		free(p[i++]);
}
