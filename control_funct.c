#include "main.h"

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
