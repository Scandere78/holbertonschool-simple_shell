#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

/**
 * Execute a command with the given arguments.
 *
 * @param args An array of strings containing the command and its arguments.
 * @param envp An array of strings containing the environment variables.
 */
void execute_command(char **args, char **envp)
{
    if (execve(args[0], args, envp) == -1)
    {
        perror("execve");
        exit(EXIT_FAILURE);
    }
}

