#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100

char *_getline(void)
{
	char *buffer = malloc(BUFSIZE);

	if (buffer == NULL)
	{
		return (NULL);
	}
	fgets(buffer, BUFSIZE, stdin);
    
	return (buffer);
}
