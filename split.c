#include <stdio.h>
#include <unistd.h>
 
void execute_ls()
{
	char *args[] = {"/bin/ls", NULL};

	execvp("/bin/ls", args);

	perror("execvp");
}
