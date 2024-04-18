#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

// Déclaration de la fonction execute_command
void execute_command(char *command);
void tokenize_and_print();
char *_getline();

#endif

