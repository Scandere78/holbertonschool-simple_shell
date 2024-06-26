#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * get_line - Obtains a line from the standard input.
 *
 * Return: NULL in case of error or end of file (EOF).
 */
char *get_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t nread;

	nread = getline(&line, &bufsize, stdin);
	if (nread == -1)
	{
		return(NULL);
	}

	if (line[nread - 1] == '\n')
	{
		line[nread - 1] = '\0';
	}

	return (line);
}

