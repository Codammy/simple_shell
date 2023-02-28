#include "header.h"
#include <stdio.h>

/**
 * func_name - desc.
 * 
 * @arg1:
 * @arg2:
 * Return: .
*/
extern char **environ;
char *_getenv(const char *name)
{
/*	int i = 0, j = 0;

	while (environ[i])
	{
		while (**environ + i +j != '=')
		{
			if (*environ[j] != name[j])
				return (null);
			j++;
		}
		i++;
	}
	return (environ[i]);*/
    return (getenv(name));
}
