#include "shell.h"
/**
 * own_cd - changes the working directory
 * @args: target directory
 * Return: 1 on success, else 0.
 */
int own_cd(char **args)
{
	if (args[1] == NULL)
		fprintf(stderr, "expected argument to \"cd\"\n");
	else
	{
		if (chdir(args[1]) != 0)
			perror("error in own_cd.c: changing dir\n");
	}
	return (-1);
}
/**
 * own_env - prints environment variables
 * @args: arguments
 * Return: 1 on success, 0 otherwise.
 */
int own_env(char **args)
{
	int i = 0;

	(void)args;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (-1);
}
/**
 * own_exit - causes normal process termination
 * @args: empty args
 * Return: 0 to terminate the process
 */
int own_exit(char **args)
{
	(void)args;
	return (0);
}
/**
 * own_help - print help
 * @args: arguments
 *
 * Return: 1 on success, 0 otherwise
 */
int own_help(char **args)
{
	char *builtin_func_list[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	unsigned int long i = 0;
	(void)(**args);

	printf("\n---help simple_shell---\n");
	printf("Type a command and its arguments, then hit enter\n");
	printf("Built-in commands:\n");
	for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
	{
		printf("  -> %s\n", builtin_func_list[i]);
	}
	printf("Use the man command for information on other programs.\n\n");
	return (-1);
}
