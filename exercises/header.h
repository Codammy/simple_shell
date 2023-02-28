#ifndef _HEADER_
#define _HEADER_
#define null NULL
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void print_path(char *s);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
#endif
