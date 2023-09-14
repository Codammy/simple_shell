#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main(int ac, char **av)
{
	int abc = 123;
	printf("%d Firsr abc: %d\n",getpid(),  abc);

	int pid = fork();
	if (pid == 0)
	{
		abc = 321;
		printf("%d Inside abc: %d\n", getpid(), abc);
	}
	else
		wait(NULL);
	printf("%d abc: %d\n", getpid(), abc);
}
