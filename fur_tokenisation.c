#include "main.h"

/**
 * _strtok - tokenizes commands
 *
 * @cmdline: line
 * @command: each token is set to index
 */
int _strtok(char *cmdline, char **command)
{
        char *cmd;
        int i = 0;

        cmd = strtok(cmdline, " ");
	if (!cmd)
	{
		free(cmdline);
		return (1);
	}
        while (cmd)
        {
                command[i] = strdup(cmd);
                i++;
                cmd = strtok(NULL, " ");
        }
        command[i] = NULL;
        free(cmdline);
	return (0);
}
