#ifndef _HEADER_
#define _HEADER_
/** Basic coding block headers */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
/** Manually add others */
#define MAXLINE 50
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
int num_arg(char *comm, char **arg);
void freeMem(char **p);
#endif
