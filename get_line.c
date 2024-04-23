#include <stdio.h>
#include <stdlib.h>

/**
 * Obtient une ligne de l'entrée standard.
 * Retourne NULL en cas d'erreur ou de fin de fichier (EOF).
 */
char *get_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t nread;

	nread = getline(&line, &bufsize, stdin);
	if (nread == -1)
	{
		if (feof(stdin))
		{
			return (NULL);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}

	if (line[nread - 1] == '\n')
	{
		line[nread - 1] = '\0';
	}

	return (line);
}

