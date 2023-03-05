#include "header.h"

/**
 * main - "description"
 * @argc: number of argumnents passed.
 * @argv: program name.
 */
char **environ;
int main(int argc, char *argv[])
{
	struct stat st;
	char *buff, *command, *hsh;
	size_t size = 3;
	int len;
	pid_t id;
	char *av[50];

	hsh = argv[0];
	buff = malloc(size);
	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			printf(">_ ");

		getline(&buff, &size, stdin);
		if (feof(stdin))
		{
			free(buff);
			if (isatty(STDIN_FILENO))
				putchar('\n');
			exit(0);
		}
		command = strtok(buff, "\n");
		len = num_arg(command, av);
		if (len == 0)
			continue;
		av[len] = NULL;

		if (stat(av[0], &st) == -1)
		{
			perror(hsh);
			freeMem(av);
			continue;
		}

		id = fork();
		if (id == 0)
		{
			execve(av[0], av, environ);
			perror(av[0]);
			free(buff);
			freeMem(av);
			exit(0);
		}
		else
		{
			wait(NULL);
		}
		freeMem(av);
		argc++;
	}
	free(buff);
}
