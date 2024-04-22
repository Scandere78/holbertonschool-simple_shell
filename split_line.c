#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGUMENTS 64

char **split_line(char *line)
{
	char *token;
	int token_count = 0;

	char **tokens = malloc(MAX_ARGUMENTS * sizeof(char *));
	if (!tokens)
	{
		perror("Allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\n");
	while (token != NULL && token_count < MAX_ARGUMENTS)
	{
		tokens[token_count++] = strdup(token);
		if (!tokens[token_count - 1])
		{
			perror("Allocation error");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " \t\n");
	}
	tokens[token_count] = NULL;
	return tokens;
}

