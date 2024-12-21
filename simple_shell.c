#include "shell.h"
/**
 * main - Entry point
 * Return: Always 0.
 */
int main(void)
{
	char *parsed_args[MAXLIST];
	char *parsed_pipe[MAXLIST];
	char *str = malloc(1024);
	int status = 1;
	ssize_t bytes_read;

	if (isatty(STDIN_FILENO))
	{
		while (status)
		{
			if (prompt_line(str) == 0)
			{
				status = process_string(str, parsed_args, parsed_pipe);
				if (status == 1)
				{
					exe_args(parsed_args);
				}
				else if (status == 2)
				{
					exe_args_piped(parsed_args, parsed_pipe);
				}
			}
		}
	}
	else
	{
		while ((bytes_read = read(STDIN_FILENO, str, 1024)) > 0)
		{
			str[bytes_read] = '\0';
			execute_non_interactive(str);
		}
	}
	free(str);
	return (0);
}
