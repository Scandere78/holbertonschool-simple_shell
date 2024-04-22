#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char **split_line(char *line);
void execute_command(char **args);
char *get_line(void);

int main(void)
{
	char *line;
	char **args;
	int status;

	while (1)
	{
		printf("$ ");
		line = get_line();
		args = split_line(line);

		if (args[0] != NULL)
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

			free(line);
			free(args);

			if (!isatty(fileno(stdin)))
			{
				break;
			}
		}
	}
	return (0);
}
