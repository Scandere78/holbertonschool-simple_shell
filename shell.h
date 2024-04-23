#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

void command_execut(char **args);
char **split_line(char *line);
char *get_line(void);
void create_envi(char **envi);
void free_env(char **env);
char *_getenv(char **env, const char *name);
char *get_path(char **env, const char *cmd_name);

#endif

