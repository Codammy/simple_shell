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
char *_stats(char *command);
int _builtins(char **command, char *b);
int _strtok(char *cmdline, char **command);
void control(char **av, char *b, char **command, int *exit_, int n);
#endif
