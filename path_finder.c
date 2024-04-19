#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * path_cmd -  Search In $PATH for executable command
 * @cmd: Parsed input
 * Return: 0 on success or  1 on failure  0
 */

int path_cmd(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = getenv("PATH");
	value = strtok(path, ":");
	while (value != NULL)
	{
		cmd_path = build(*cmd, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		value = strtok(NULL, ":");
	}
	free(path);
	free(value);
	return (1);
}

/**
 * build - Build command
 * @token: Executable command
 * @value: Directory conatining Command
 * Return: Parsed full path of command or NULL if failed
 */
char *build(char *token, char *value)
{
	char *cmd;
	size_t len;

	len = strlen(value) + strlen(token) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		free(cmd);
		return (NULL);
	}

	memset(cmd, 0, len);

	cmd = strcat(cmd, value);
	cmd = strcat(cmd, "/");
	cmd = strcat(cmd, token);

	return (cmd);
}

