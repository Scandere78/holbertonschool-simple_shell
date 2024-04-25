#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"

int main(int argc, char **argv, char **env)
{
	char *line;
	char **args;
	int status;
	pid_t pid;
	(void)argc;
	(void)argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		fflush(stdout);
		line = get_line();
		if (line == NULL)
		{
			break;
		}
		args = split_line(line);
		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				free(line);
				free(args);
				exit(EXIT_SUCCESS);
			}

			pid = fork();

			if (pid == -1)
			{
				perror("fork");
			}
			else if (pid == 0)
			{
				execute_command(args, env);
			}
			else
			{
				waitpid(pid, &status, WUNTRACED);
			}
			free(line);
			free(args);
		}
	}
	return (0);
}
