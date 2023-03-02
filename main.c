#include "header.h"

/**
 * main - simple shell.
 * @argc: number of arguments passed at run time.
 * @argv: array of pointers to string (passed at run time)
 *
 * Return: 0.
*/
void _sig_handler(int sig)
{
	sig = sig;
	exit(0);
}
int main(int argc __attribute__((unused)), char *argv[])
{
	pid_t pid;
	char *buf, *command, *shell_name = argv[0];
	int status, line;
	size_t size = 0;

	line = 1;
	while (1)
	{
		pid = fork();
		if (pid == 0)
		{
                printf("$ ");

		getline(&buf, &size, stdin);
		/*if (feof(stdin))
		{
			fflush(NULL);
			kill(0, SIGINT);
		}*/
		fflush(NULL);

		command = strtok(buf, "\n");
		argv[0] = command;
		argv[1] = NULL;

		execve(argv[0], argv, NULL);
		dprintf(STDERR_FILENO, "%s: %d: %s: not found\n", shell_name, line, argv[0]);
		exit(0);
	}
	else
		wait(&status);
	line++;
	}
	return (0);
}
