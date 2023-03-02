#include "header.h"

/**
 * main - "description"
 *
 *
 */
char **environ;
int main(int argc, char *argv[])
{
	struct stat st;
	char *buff, *command, *hsh;
	size_t size = 0;
	pid_t id;
	char *av[50];
	hsh = argv[0];

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			printf(">_ ");

		getline(&buff, &size, stdin);
		if (feof(stdin) && isatty(STDIN_FILENO))
		{
			putchar('\n');
			exit(0);
		}
		command = strtok(buff, "\n");
		av[0] = command;
		av[1] = NULL;

		if (stat(av[0], &st) == -1)
			perror(hsh);
		id = fork();
		if (id == 0)
		{
			execve(av[0], av, environ);
			exit(0);
		}
		else
		{
			wait(NULL);
			if (isatty(STDIN_FILENO) == 0)
				exit(0);
		}
		argc++;
	}
}
