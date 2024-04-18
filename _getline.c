#include <stdio.h>
#include <stdlib.h>

/**
 * _getline - read input from standard input by user
 * Return: the input on a buffer
 */

char *_getline()
{
	char *buffer = NULL;
	size_t buffsize = 0;
	ssize_t rd;

	rd = getline(&buffer, &buffsize, stdin);

	if (rd == -1)
	{
	free(buffer);
	exit(EXIT_FAILURE);
	}

	if (buffer[rd - 1] == '\n')
	buffer[rd - 1] = '\0';

	return (buffer);
}
