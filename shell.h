#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void fur_prompt(void);
void ebu_dami_print(const char *de_str);
void entries_execution(const char *entries);
void user_entries(char *entries, size_t size);

#endif
