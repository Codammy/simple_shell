#include "header.h"

/**
 * main - drives functons.
 * 
 * @argc:
 * @argv:
 * @env:
 * Return: .
*/

int main(int argc, char **argv, char **env)
{
	int len;
	/*program driver*/
	char *test; 
	len = _setenv("COMPANY", "Lao-technologies", 1);
	if (len != 0)
	{printf("Error\n");exit(1);}

	test = _getenv("COMPANY");
	len = strlen(test);
	if (test == null)
		printf("%s undefined\n", test);
	else
		print_path(test);
	len = _unsetenv("COMPANY");
	if (len == -1)
		perror("Error");
	test = _getenv("COMPANY");
        if (test == null)
                printf("%s undefined\n", test);
        else
                print_path(test);

	return (0);
}
