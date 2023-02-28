#include "header.h"

/**
 * _setenv - adds an environment variablee
 *
 * @name: var name
 * @value: content to add
 * @overwrite: overwrite status
 *
 * Return: 0 on sucess or -1 if fails.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	return(setenv(name, value, overwrite));
}
