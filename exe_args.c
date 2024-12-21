#include "shell.h"
/**
 * exe_args - execute system commands
 * @parsed: param to evaluate
 * Return: void.
 */
void exe_args(char **parsed)
{
	char *path_env = getenv("PATH");
	char *path_cpy;
	char *path;
	char full_path[1024];
	pid_t pid;

	if (path_env == NULL)
	{
		perror("Error: PATH not set");
		return;
	}

	path_cpy = strdup(path_env);
	path = strtok(path_cpy, ":");

	pid = fork();

	if (pid == -1)
	{
		perror("fork failed");
		free(path_cpy);
		return;
	}
	else if (pid == 0)
	{
		while (path != NULL)
		{
			snprintf(full_path, sizeof(full_path), "%s/%s", path, parsed[0]);
			if (access(full_path, F_OK) == 0)
			{
				break;
			}
			path = strtok(NULL, ":");
		}
		if (path == NULL)
		{
			fprintf(stderr, "%s: command not found\n", parsed[0]);
			free(path_cpy);
			exit(1);
		}
		if (execve(full_path, parsed, NULL) < 0)
		{
			perror("Error executing command");
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
	free(path_cpy);
}
