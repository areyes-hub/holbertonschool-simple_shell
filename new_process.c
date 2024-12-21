#include "shell.h"
/**
 * find_in_path - finds the path to the executable passed
 * @cmd: command to execute
 * Return: Full path if found, else NULL.
 */
char *find_in_path(char *cmd)
{
	char *path = getenv("PATH");
	char *dir = strtok(path, ":");
	char *full_path = NULL;
	size_t len;

	while (dir != NULL)
	{
		len = strlen(dir) + strlen(cmd) + 2;
		full_path = malloc(len);
		if (full_path == NULL)
		{
			perror("error allocating memory");
			exit(EXIT_FAILURE);
		}
		snprintf(full_path, len, "%s/%s", dir, cmd);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		full_path = NULL;
		dir = strtok(NULL, ":");
	}
	return (NULL);
}
/**
 * new_process - create a new process
 * @args: an array of strings that contain the
 * command and its flags
 * Return: 1 if success, 0 otherwise.
 */
int new_process(char **args)
{
	pid_t pid;
	int status;
	char *path;

	pid = fork();
	if (pid == 0)
	{
		if (access(args[0], X_OK) == 0)
			path = args[0];
		else
		{
			path = find_in_path(args[0]);
			if (path == NULL)
			{
				fprintf(stderr, "error in new_process: command not found %s\n", args[0]);
				exit(EXIT_FAILURE);
			}
		}
		if (execve(path, args, environ) == -1)
		{
			perror("error in new_process: child process");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
		perror("error in new process: forking");
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}
