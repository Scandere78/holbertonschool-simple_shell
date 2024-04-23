#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char *get_line(void);
char **split_line(char *line);
void execute_command(char **args);

int main(void)
{
	char *line;
	char **args;
	int status;

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
			if (strcmp(args[0], "ls") == 0)
			{
				char *command[] = {"/bin/ls", NULL};

				execute_command(command);
			}
			else
			{
				pid_t pid = fork();

				if (pid == -1)
				{
					perror("fork");
				}
				else if (pid == 0)
				{
					execute_command(args);
				}
				else
				{
					waitpid(pid, &status, WUNTRACED);
				}
			}

			free(line);
			free(args);
		}
	}

	return (0);
}
