#include "header.h"

/**
 * main - simple shell program.
 * 
 * @arg1:
 * @arg2:
 * Return: .
*/

extern char **environ;
int main(int __attribute__((unused)) argc, char **arg)
{
	pid_t pid;
	int i, error_line = 1, status;
	char *av[MAXLINE], *buf, *command, *shell_name;
	size_t length = 0;

	shell_name = arg[0];

	while(1)
	{
		i = 0;
	/*	printf(">_ ");*/
		getline(&buf, &length, stdin);
		fflush(NULL);
		if (feof(stdin))
		{
		free(buf);
	/*	putchar('\n');*/
		exit(0);
		}
		command = strtok(buf, " ");
		
		if (command[0] == '\n' || command[0] == '\0')
		{
			error_line++;
			continue;
		}
		av[0] = malloc(strlen(command) * sizeof(char) - 1);
		if (av[0] == NULL)
		{printf("error ocuured"); exit(1);}
		while (command[i] != '\n')
		{
			*(av[0] + i) = command[i];
			i++;
		}
		av[1] = NULL;

		pid = fork();
		if (pid == 0)
		{
		execve(av[0], av, environ);
		dprintf(1, "%s: %d: %s: not found\n", shell_name, error_line, av[0]);
		exit(0);
		}
		else
			wait(&status);;
		free(av[0]);
		error_line++;
	}
	free(buf);
	return (0);
}
