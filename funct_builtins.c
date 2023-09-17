#include "main.h"

/**
 * _builtins - checks for builtins
 * @command: commands
 *
 * Return: 0 on Success
 */
int _builtins(char **command, char *b)
{
        int i;

        if (strcmp(command[0], "exit") == 0)
        {
		_free(command);
		free(b);
                exit(0);
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
