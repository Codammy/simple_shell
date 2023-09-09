#include "shell.h"

void ebu_dami_print(const char *de_str)
{
	write(STDOUT_FILENO, de_str, strlen(de_str));
}
