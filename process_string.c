#include "shell.h"
/**
 * process_string - process input strings
 * @str: first param
 * @parsed: second param
 * @parsed_pipe: third param
 * Return: On success, 0. On failure >0.
 */
int process_string(char *str, char **parsed, char **parsed_pipe)
{
	char *str_piped[3];
	int piped = 0;

	piped = parse_pipe(str, str_piped);
	if (piped)
	{
		parse_space(str_piped[0], parsed);
		parse_space(str_piped[1], parsed_pipe);
	}
	else
	{
		parse_space(str, parsed);
	}
	if (cmd_handler(parsed))
	{
		return (0);
	}
	return (1 + piped);
}
