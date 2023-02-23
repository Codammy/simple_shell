#include "header.h"

/**
 * main - simple shell.
 * @argc: number of arguments passed at run time.
 * @argv: array of pointers to string (passed at run time)
 *
 * Return: 0.
*/

int line_checker(char *line);
int main(int argc __attribute__((unused)), char *argv[])
{
	struct stat st;
	pid_t pid;
	char *buf, *command, *shell_name, *new, *me;
	int status, i = 0, j = 0;
	size_t size = 0;

	shell_name = argv[0];
	while (1)
	{
	pid = fork();
	if (pid == 0)
	{
		printf("#cisfun$ ");
		
		if (getline(&buf, &size, stdin) == -1)
			exit(1);

		command = strtok(buf, " ");
		//printf("%s\n", command);
		argv[j] = malloc(strlen(command) * sizeof(char) - 1);
			if (argv[j] == NULL)
				printf("malloc :\n");
		while (command[i] != '\n' && command[i] != '\0')
		{
			*(argv[j] + i) = command[i];
			i++;
		} j++;
		command = strtok(NULL, "\n");
		if (command != NULL)
		{
			i = 0;
			argv[j] = malloc(strlen(command) * sizeof(char) - 1);
			if (argv[j] == NULL)
				perror(argv[0]);
			while (command[i] != '\n')
			{
				*(argv[j] + i) = command[i];
				i++;
			}
		} j++;
		argv[j] = NULL;
		/*printf("%s\n", argv[1]);*/
		//if (stat(command, &st) == -1)
		//{
		//	dprintf(2, "%s: 1: %s: not found\n", shell_name, argv[0]);
		//	exit(1);
		//}
		if (execve(argv[0], argv, NULL))
		{
			dprintf(1, "%s: 1: %s: not found\n", shell_name, argv[1]);
			exit(1);
		}
		int f = 0;
		while (argv[f] != NULL)
			free(argv[f++]);
	}
	else
		wait(&status);
	}
	free(buf);
	return (0);
}
