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

			pid_t pid = fork();

			if (pid == -1)
			{
				perror("fork");
			}
			if (command_exists(args[0]) == 0)
			{
				printf("%s: command not found\n", args[0]);
				continue;
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

