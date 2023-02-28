#include "header.h"
#include <stdio.h>

/**
 * print_path - prints each directory contained in a path
 *
 * @env: 
 */
void print_path(char *s)
{
	int i = 0;

	printf("%s\n", s);
	while (i < strlen(s))
	{
		while (s[i] != '\0' && s[i] != ':')
		{
			putchar(s[i]);
		i++;
		}
		i++;
		putchar('\n');
	}
}
