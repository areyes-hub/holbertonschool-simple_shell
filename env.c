#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_env - prints environment
 * Return: void.
 */
/*extern char **environ;*/

void print_env(void)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork failed");
		return;
	}
	if (pid == 0)
	{
		char *env_cmd[] = {"/usr/bin/env", NULL};

		if (execve(env_cmd[0], env_cmd, environ) == -1)
		{
			perror("Error running env command");
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
}
