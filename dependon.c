#include "header.h"

/**
 * num_arg - checks if command has argument.
 *
 * @comm: command.
 * @arg: array of strings to store command temporarily
 * Return: number of elements in arg (int).
 */
int num_arg(char *comm, char **arg)
{
        char *xend;
        int i = 0;

        xend = strtok(comm, " ");
        while (xend != NULL)
        {
                arg[i] = trim_whitesp(xend);
                xend = strtok(NULL, " ");
                i++;
        }
        return(i);
}

/**
 * trim_whitesp - removes trailing whitespace
 *
 * @s: command or argument
 * Return: command or argument.
 */
char *trim_whitesp(char *s)
{
        char *tok, *new;
        int count = 0, i = 0, j = 0;

        tok = strtok(s, " ");
        while (tok != NULL)
                tok = strtok(NULL, " ");
        while (s[i])
        {
                if (s[i] == ' ')
                {
                        i++;
                        continue;
                }
                count++;
                i++;
        }
        i = 0;
        new = malloc(count * sizeof(char));
        while (s[i])
        {
                if (s[i] == ' ')
                {
                        i++;
                        continue;
                }
                new[j] = s[i];
                j++;
                i++;
        }
        return (new);
}
