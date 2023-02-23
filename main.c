#include "header.h"

/**
 * main - simple shell.
 * @argc: number of arguments passed at run time.
 * @argv: array of pointers to string (passed at run time)
 *
 * Return: 0.
*/
int main(int argc __attribute__((unused)), char *argv[])
{
	struct stat st;
	pid_t pid;
	char *buf, *command, *shell_name;
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
		argv[j] = malloc(strlen(command) * sizeof(char) + 1);
		if (argv[j] == NULL)
		{
			printf("malloc :\n");
			exit(1);
		}
		while (command[i] != '\n' && command[i] != '\0')
		{
			*(argv[j] + i) = command[i];
			i++;
		}
		j++;
		command = strtok(NULL, " ");
		while (command != NULL && command != "\n")
		{
			i = 0;
			argv[j] = malloc(strlen(command) * sizeof(char) + 1);
			if (argv[j] == NULL)
			{
				perror(argv[0]);
				exit(1);
			}
			while (command[i] != '\n')
			{
				*(argv[j] + i) = command[i];
				i++;
			}
			command = strtok(NULL, " ");
			j++;
		}
		argv[j] = NULL;
		/*printf("%s\n", argv[1]);*/
		//if (stat(command, &st) == -1)
		//{
		//	dprintf(2, "%s: 1: %s: not found\n", shell_name, argv[0]);
		//	exit(1);
		//}
		if (execve(argv[0], argv, NULL))
		{
			dprintf(1, "%s: 1: %s: not found\n", shell_name, argv[0]);
			exit(1);
		}
		j = 0;
		while (argv[j] != NULL)
			free(argv[j++]);
	}
	else
		wait(&status);
	}
	free(buf);
	return (0);
}
