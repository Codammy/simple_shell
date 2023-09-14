#include "main.h"

/**
 * _strtok - tokenizes commands
 *
 * @cmdline: line
 * @command: each token is set to index
 */
void _strtok(char *cmdline, char **command)
{
        char *cmdl, *cmd;
        int i = 0;

        cmdl = strdup(cmdline);
        cmd = strtok(cmdl, " ");
        while (cmd)
        {
                command[i] = strdup(cmd);
                i++;
                cmd = strtok(NULL, " ");
        }
        command[i] = NULL;
        free(cmdl);

}
