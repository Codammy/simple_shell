#include "main.h"

/**
 * _stats - checks for the command status and fix path
 *
 * @command: commands.
 * Return: 0 on sucess.
 */

int _stats(char **command)
{
        char *path, *cmd, *tmp, *current_path;
        struct stat file_info;

        if (**command == '/')
        {
                if (stat(command[0], &file_info) == 0)
                        return (0);
                return (1);
        }
        path = strdup(getenv("PATH"));
        tmp = strtok(path, ":");
        while (tmp)
        {
                current_path = strdup(tmp);
                cmd = malloc(strlen(current_path) + strlen(command[0]) + 1);
                sprintf(cmd, "%s/%s", current_path, command[0]);
                if (stat(cmd, &file_info) == 0)
                {
                        free(command[0]);
                        free(current_path);
                        command[0] = cmd;
                        return (0);
                }
                free(cmd);
                free(current_path);
                tmp = strtok(NULL, ":");
        }
        free(path);
	return (1);
}
