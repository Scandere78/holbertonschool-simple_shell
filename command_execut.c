#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void execute_command(char **args)
{
	if (execve(args[0], args, NULL) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}
