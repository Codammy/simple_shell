#include "main.h"

/**
 * _builtins - checks for builtins
 * @c: commands
 * @p: program name
 * @l: line number
 * @s: status code
 * @b: buffer
 *
 * Return: 0 on Success
 */
int _builtins(char **c, char *p, int l, int *s, char *b)
{
	int i, status = *s;

	if (strcmp(c[0], "exit") == 0)
	{
		if (c[1])
		{
			status = atoi(c[1]);
			if (status == 0 || status < 0)
			{
				dprintf(STDERR_FILENO, "%s: %d: exit: Illegal number: %s\n", p, l, c[1]);
				*s = 2;
				_free(c);
				return (0);
			}
		}
		_free(c);
		free(b);
		exit(status);
	}
	if (strcmp(c[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
		_free(c);
		return (0);
	}
	return (1);
}
