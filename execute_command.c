#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include "shell.h"
/**
 * Execute a command with the given arguments.
 *
 * @param args An array of strings containing the command and its arguments.
 * @param envp An array of strings containing the environment variables.
 */
void execute_command(char **args, char **envp)
{
	if (args[0][0] != '/')
	{
		char *path = get_path(envp, args[0]);
		if (path == NULL)
		{
			fprintf(stderr, "Command not found: %s\n", args[0]);
			exit(EXIT_FAILURE);
		}
		args[0] = path;
		
	}
	if (execve(args[0], args, envp) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

