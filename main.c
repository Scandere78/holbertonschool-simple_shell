#include <stdio.h>
#include <stdlib.h>

int my_function(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("usage: %s arg1 arg2\n", argv[0]);
		return (1);
	}

	printf("Argument 1 : %s\n", argv[1]);
	printf("Argument 2 : %s\n", argv[2]);

	return (0);
}
