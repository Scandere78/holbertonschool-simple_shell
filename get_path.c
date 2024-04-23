#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"


/**
 * get_path - get a path for execute cmd
 * @env: liste of variable environment
 * @cmd_name: name of command to get
 * Return: Variable value of environment_path or NULL
 */

char *get_path(char **env, const char *cmd_name)
{
	char *path_copy, *dir, *cmd_path = NULL;
	size_t cmd_path_size = 0;
	char *env_path = _getenv(env, "PATH");

	if (env_path == NULL)
	return (NULL);

	path_copy = strdup(env_path);
	if (!path_copy)
	return (NULL);

	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
	cmd_path_size = strlen(dir) + strlen(cmd_name) + 2;
	cmd_path = (char *)malloc(cmd_path_size);
	if (cmd_path == NULL)
	return (NULL);

	strcpy(cmd_path, dir);
	strcat(cmd_path, "/");
	strcat(cmd_path, cmd_name);

	if (access(cmd_path, X_OK) == 0)
	{
	free(path_copy);
	return (cmd_path);
	}

	free(cmd_path);
	dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
