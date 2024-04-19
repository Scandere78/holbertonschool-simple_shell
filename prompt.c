#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

int main() 
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
		system(command);
	}

	return 0;
}

