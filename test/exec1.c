#include <stdio.h>
#include <unistd.h>

int main()
{
	char *args[] = {"ls", "-l", NULL};
	if (execve("/bin/ls", args, NULL) == -1)
	{
		perror("exceve");
	}

	printf("This will not be printed if execve is successful.\n");

	return (0);
}
