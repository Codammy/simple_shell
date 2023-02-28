#include <stdio.h>
#include <stdlib.h>

/**
 * env vs environ - compares the address of env and environ.
 *
 * Return: 0
 */

extern char **environ;
int main(int argc, char **argv, char **env)
{
	printf("%p\n%p\n", env, environ);

	return (0);
}
