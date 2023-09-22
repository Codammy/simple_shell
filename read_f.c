#include "main.h"

/**
 * read_file - reads from file
 *
 * @f: file to read from
 * @p: program name incase of error printing
 * Return: stdin or pointer to fike(depending on file existence)
 */
FILE *read_file(char *f, char *p)
{
	FILE *stream;

	if (f)
	{
		stream = fopen(f, "r");
		if (!stream)
		{
			dprintf(STDERR_FILENO, "%s: 0: cannot open %s: No such file\n", p, f);
			exit(127);
		}
		return (stream);
	}
	return (stdin);
}
