#include "shell.h"
/**
 * main - Entry point
 * @argc: arg count
 * @argv: arg array
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *parsed_args[MAXLIST], *parsed_pipe[MAXLIST], *str = malloc(1024);
	int status = 1, i;
	ssize_t bytes_read;

	if (argc > 1)
	{
		str[0] = '\0';
		for (i = 1; i < argc; i++)
		{
			strcat(str, argv[i]);
			if (i < argc - 1)
				strcat(str, " ");
		} status = process_string(str, parsed_args, parsed_pipe);
		if (status == 1)
			exe_args(parsed_args);
		else if (status == 2)
			exe_args_piped(parsed_args, parsed_pipe);
	} else
		if (isatty(STDIN_FILENO))
		{
			while (status)
			{
				if (prompt_line(str) == 0)
				{
					status = process_string(str, parsed_args, parsed_pipe);
					if (status == 1)
						exe_args(parsed_args);
					else if (status == 2)
						exe_args_piped(parsed_args, parsed_pipe);
				}
			}
		} else
		{
			while ((bytes_read = read(STDIN_FILENO, str, 1024)) > 0)
			{
				str[bytes_read] = '\0';
				execute_non_interactive(str);
			}
		} free(str);
	return (0);
}
