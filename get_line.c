#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *get_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}

	line[strcspn(line, "\n")] = '\0';
	return (line);
}
