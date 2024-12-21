#include "shell.h"
/**
 * cmd_handler - executes built-in commands
 * @parsed: parameter to evaluate
 * Return: On success , 1. Else, 0.
 */
int cmd_handler(char **parsed)
{
	int cmd_count = 3, i, switch_arg = 0;
	char *cmd_list[3];

	cmd_list[0] = "exit";
	cmd_list[1] = "env";
	cmd_list[2] = "cd";

	for (i = 0; i < cmd_count; i++)
	{
		if (strcmp(parsed[0], cmd_list[i]) == 0)
		{
			switch_arg = i + 1;
			break;
		}
	}
	switch (switch_arg)
	{
		case 1:
			exit(0);
		case 2:
			print_env();
			return (0);
		case 3:
			return (handle_cd(parsed));
		default:
			break;
	}
	return (0);
}
