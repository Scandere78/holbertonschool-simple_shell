#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_ARGUMENTS 64

/**
 * Sépare une ligne en tokens (mots) en utilisant des espaces comme délimiteurs.
 * Retourne un tableau de chaînes de caractères (tokens).
 */

char **split_line(char *line)
{
	char *token;
	int token_count = 0;

	char **tokens = malloc(MAX_ARGUMENTS * sizeof(char *));

	if (tokens == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " ");
	while (token != NULL && token_count < MAX_ARGUMENTS - 1)
	{
		tokens[token_count] = strdup(token);
		if (tokens[token_count] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		token_count++;
		token = strtok(NULL, " ");
	}
	tokens[token_count] = NULL;

	return (tokens);
}

