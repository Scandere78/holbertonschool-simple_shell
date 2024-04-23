#include "shell.h"
#include <stdlib.h>
#include <unistd.h>

/**
*_getenv - get a variable environment
*@env: list of variables environment
*@name: name of get
*Return: Variable value of environment or NULL
*/
char *_getenv(char **env, const char *name) {
        int i = 0;

        while (env[i] != NULL) {
                if (strncmp(env[i], name, strlen(name)) == 0 && (env[i])[strlen(name)] == '=') {
                        return (env[i] + strlen(name) + 1);
                }
                i++;
        }
        return (NULL);

}


/**
 *get_path - get a path for execute cmd
 *@env: liste of variable environment
 *@cmd_name: name of command to get
 *Return Variable value of environment_path or NULL
 */
char *get_path(char **envp, char *cmd_name)
{
	char *env_path = _getenv(envp, "PATH");
	char *token;
	char *path = NULL;

	token = strtok(env_path, ":");
	while (token != NULL)
	{
		char *full_path = malloc(strlen(token) + strlen(cmd_name) + 2);
		
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, cmd_name);

		if (access(full_path, X_OK) == 0)
		{
			path = strdup(full_path);
			free(full_path);
			break;
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	return (path);
}

