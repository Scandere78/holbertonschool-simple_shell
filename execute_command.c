#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include "shell.h"
/**
 * execute_command - Execute a command with the given arguments.
 *
 * This function executes the command specified by the given arguments.
 *
 * @args: An array of strings containing the command and its argumentsi.
 * @envp: An array of strings containing the environment variables.
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

