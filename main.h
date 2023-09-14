#ifndef MAIN
#define MAIN
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
FILE *read_file(char *file, char *pname);
void _free(char **command);
int _stats(char **command);
int _builtins(char **command);
void _strtok(char *cmdline, char **command);
void control(char **av, char *cmdline, char **command, int *exit_, int n);
#endif
