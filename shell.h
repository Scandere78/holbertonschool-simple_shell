#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

char *get_line(void);
void execute_command(char **args, char **envp);
char **split_line(char *line);
char *get_path(char **envp, char *cmd_name);
#endif
