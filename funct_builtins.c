#include "main.h"

/**
 * _builtins - checks for builtins
 * @command: commands
 * @b: buffer
 *
 * Return: 0 on Success
 */
int _builtins(char **command, char *b)
{
	int i, status = 0;

	if (strcmp(command[0], "exit") == 0)
	{
		if (command[1])
		{
			status = atoi(command[1]);
			if (status == 0)
				status = 2;
		}
		_free(command);
		free(b);
		exit(status);
	}
	if (strcmp(command[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
			printf("%s\n", environ[i]);
		_free(command);
		return (0);
	}
	return (1);
}
