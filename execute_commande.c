#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

void execute_command(char *command)
{
	pid_t pid = fork();
	
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
		execlp(command, command, NULL);
		
		fprintf(stderr, "Command not found: %s\n", command);
		exit(EXIT_FAILURE);
	} else
	{
		wait(NULL);
	}
}

int main(void) 
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("$ ");
		
		if (fgets(command, sizeof(command), stdin) == NULL) 
		{
			printf("\n");
			break;
		}
		
		command[strcspn(command, "\n")] = '\0';
		
		execute_command(command);
	}

	return 0;
}

