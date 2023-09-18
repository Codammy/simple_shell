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

        strtok(cmdline, "\0");
        cmd = strtok(cmdline, " ");
        while (cmd)
        {
		command[i] = strdup(cmd);
                cmd = strtok(NULL, " ");
		i++;
        }
	if (i == 0) return (1);
        command[i] = NULL;
	return (0);
}
