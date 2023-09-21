#include "main.h"

/**
 * _stats - checks for the command status and fix path
 *
 * @command: command.
 * Return: full command path.
 */
char *_stats(char *command)
{
	char *path, *cmd, *tmp, *current_path;
	struct stat file_info;

	if (*command == '.')
		return (command);
	if (*command == '/')
	{
		if (stat(command, &file_info) == 0)
			return (command);
		return (NULL);
	}
	path = strdup(getenv("PATH"));
	tmp = strtok(path, ":");
	while (tmp)
	{
		current_path = strdup(tmp);
		cmd = malloc(64);
		sprintf(cmd, "%s/%s", current_path, command);
		free(current_path);
		if (stat(cmd, &file_info) == 0)
		{
			free(command);
			while (tmp)
				tmp = strtok(NULL, ":");
			free(path);
			return (cmd);
		}
		free(cmd);
		tmp = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
