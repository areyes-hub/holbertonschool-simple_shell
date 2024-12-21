#include "shell.h"
/**
 * parse_pipe - finds pipe
 * @str: first param
 * @str_piped: second param
 * Return: On success, 1. Else, 0.
 */
int parse_pipe(char *str, char **str_piped)
{
	int i;

	for (i = 0; i < 2; i++)
	{
		str_piped[i] = strsep(&str, "|");
		if (str_piped[i] == NULL)
		{
			break;
		}
	}
	if (str_piped[1] == NULL)
	{
		return (0);
	}
	return (1);
}
