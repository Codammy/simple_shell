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
        size_t size = 0, n = 0;
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
			free(buffer);
                        exit(exit_status);
                }
                fflush(stream);
                control(av, buffer, command, &exit_status, n);
               // free(buffer);
        }
        fclose(stream);
        return (exit_status);
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
