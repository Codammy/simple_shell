#include "header.h"

/**
 * func_name - desc.
 * 
 * @arg1:
 * @arg2:
 * Return: .
*/

int main()
{
	char *buff;
	size_t num = 0;
	int new = 1;
	while(feof(stdin) == 0)
	{
		printf("Input: ");
		new = getline(&buff, &num, stdin);
		printf("Output: %s", buff);
		getline(&buff, &num, stdin);
	}
	printf("End of process\n");
    return 0;
}
