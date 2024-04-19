#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100


void execute_command(char *command);
void tokenize_and_print();
char *_getline();
int path_cmd(char **cmd);
char *build(char *token, char *value);
#endif

