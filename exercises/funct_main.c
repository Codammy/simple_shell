#include "main.h"

/**
 * main - simple shell program
 *
 * @ac: number of command line args.
 * @av: command line args.
 * Return: 0 on Success.
 */
int main(int __attribute__((unused)) ac, char **av)
{
	int exit_status = 0;
	unsigned int size = 0, n = 0;
	char *buffer = NULL, *command[1024], *cmdline;
	FILE *stream;

	stream = read_file(av[1], av[0]);
	while (1)
	{
		n++;
		if (isatty(STDIN_FILENO) && stream == stdin)
			printf(">_ ");
		if (getline(&buffer, &size, stream) == -1)
		{
			if (isatty(STDIN_FILENO) && stream == stdin)
				putchar('\n');
			exit(exit_status);
		}
		fflush(stream);
		cmdline = strtok(buffer, "\n");
		control(av, cmdline, command, &exit_status, n);
		free(buffer);
	}
	fclose(stream);
	return (exit_status);
}

/**
 * read_file - reads from file
 *
 * @file: file to read from
 * @pname: program name incase of error printing
 * Return: stdin or pointer to fike(depending on file existence)
 */
FILE *read_file(char *file, char *pname)
{
	FILE *stream;

	if (file)
	{
		stream = fopen(file, "r");
		if (!stream)
		{
			dprintf(STDERR_FILENO, "%s: 0: cannot open %s: No such file", pname, file);
			exit(errno);
		}
		return (stream);
	}
	return (stdin);
}

/**
 * control - controls program behaviour
 *
 * @av: commandline option
 * @cmdline: splited lines
 * @command: commands
 * @exit_: keep tracks of programme exit status
 * @n: line number
 */
void control(char **av, char *cmdline, char **command, int *exit_, int n)
{
	pid_t pid;
	int st;

	while (cmdline)
	{
		_strtok(cmdline, command);
		if (_builtins(command) == 0)
		{
			cmdline = strtok(NULL, "\n");
			continue;
		}
		if (_stats(command) != 0)
		{
			dprintf(STDERR_FILENO, "%s: %u: %s: not found\n", av[0], n, command[0]);
			_free(command);
			*exit_ = 127;
			cmdline = strtok(NULL, "\n");
			continue;
		}
		pid = fork();
		if (pid == 0)
			execve(command[0], command, environ);
		else
		{
			wait(&st);
			*exit_ = WEXITSTATUS(st);
			_free(command);
			cmdline = strtok(NULL, "\n");
		}
	}
}

/**
 * _stats - checks for command status and fix path
 *
 * @command: commands
 * Return: 0 on Success
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

/**
 * _builtins - checks for builtins
 * @command: commands
 *
 * Return: 0 on Success
 */
int _builtins(char **command)
{
	int i;

	if (strcmp(command[0], "exit") == 0)
	{
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

/**
 * _free - frees command
 *
 * @command: command to free
 */
void _free(char **command)
{
	int index = 0;

	while (command[index])
	{
		free(command[index]);
		index++;
	}
}
