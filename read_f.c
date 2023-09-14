#include "main.h"

/**
 * read_file - reads from file
 *
 * @file: file to read from
 * @pname: program name incase of error printing
 * Return: stdin or pointer to fike(depending on file existence)
 */
FILE *read_file(char *file, char *pname)
{
        FILE *stream;

        if (file)
        {
                stream = fopen(file, "r");
                if (!stream)
                {
                        dprintf(STDERR_FILENO, "%s: 0: cannot open %s: No such file", pname, file);
                        exit(errno);
                }
                return (stream);
        }
        return (stdin);
}
