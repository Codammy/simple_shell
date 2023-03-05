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
        int i, j = 0, len = 0;

        xend = strtok(comm, " ");
        while (xend != NULL)
        {
		i = 0;
		while (xend[i])
			i++;
                arg[j] = malloc(i * sizeof(char));
		i = 0;
		while (xend[i])
		{
			*(arg[j] + i) = xend[i];
			i++;
		} j++;
                xend = strtok(NULL, " ");
		len++;
        }
        return(len);
}
