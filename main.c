#include "header.h"

/**
 * main - simple shell.
 * @argc: number of arguments passed at run time.
 * @argv: array of pointers to string (passed at run time)
 *
 * Return: 0.
*/
int main(int argc __attribute__((unused)), char *argv[], char *env[])
{
/*	struct stat st;*/
	pid_t pid;
	char *buf, *command, *shell_name;
	int status, i = 0, j = 0, c = 1;
	size_t size = 0;

	shell_name = argv[0];
	while (1)
	{	
		printf("#standalone$ ");

		if (getline(&buf, &size, stdin) == -1)
			exit(1);
		/*env = getenv("PATH");*/
		command = strtok(buf, " ");
		argv[j] = malloc(strlen(command) * sizeof(char) + 1);
		if (argv[j] == NULL)
		{
			printf("malloc :\n");
			exit(1);
		}
		while ((command[i] != '\n') && (command[i] != '\0'))
		{
			*(argv[j] + i) = command[i];
			i++;
		}
		j++;
		command = strtok(NULL, " ");
		while ((command != NULL) && (*command != '\0'))
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
		
		pid = fork();
                if (pid == 0)
                {
			if (execve(argv[0], argv, env))
			{
				dprintf(1, "%s: %d: %s: not found\n", shell_name, c, argv[0]);
				exit(1);
			}
		}
		else
			wait(&status);
		i = 0, j = 0, c++;
	}
	free(buf);
	return (0);
}
