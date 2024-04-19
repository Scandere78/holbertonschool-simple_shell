#include <stdio.h>
#include <string.h>
 
void tokenize_and_print()
{
	char str[] = "hello world, this is a test";
		char *token;

	token = strtok(str, " ");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
}
