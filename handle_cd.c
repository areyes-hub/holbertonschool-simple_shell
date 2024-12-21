#include "shell.h"
/**
 * handle_cd - handles the cd command
 * @parsed: parameter to evaluate
 * Return: void.
 */
int handle_cd(char **parsed)
{
	char *dir = parsed[1];
	char current_dir[MAXLIST];

	if (getcwd(current_dir, sizeof(current_dir)) != NULL)
	{
		setenv("OLDPWD", current_dir, 1);
	}
	if (dir == NULL)
	{
		dir = getenv("HOME");
		if (dir == NULL)
		{
			fprintf(stderr, "cd: HOME not set\n");
			return (1);
		}
	}
	if (chdir(dir) != 0)
	{
		perror("cd");
		return (1);
	}
	if (getcwd(current_dir, sizeof(current_dir)) != NULL)
	{
		setenv("PWD", current_dir, 1);
	}
	else
	{
		perror("getcwd");
		return (1);
	}
	return (0);
}
