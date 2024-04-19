#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define PROMPT "#cisfun$ "

int main(void) 
{
	char input[MAX_INPUT_LENGTH];

	while (1) 
	{
		printf("%s", PROMPT);

		if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break;
		}

		input[strcspn(input, "\n")] = '\0';
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{

			if (strcmp(input, "ls") == 0)
			{
				execl("/bin/ls", "ls", NULL);
				perror("execl");
				exit(EXIT_FAILURE);
			}

			else
			{
				fprintf(stderr, "commande inconnue: %s\n", input);
				exit(EXIT_FAILURE);
			}
		}

		else
		{
			wait(NULL);
		}
	}

	return (0);
}

