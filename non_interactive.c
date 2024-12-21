#include "shell.h"
/**
 * execute_non_interactive - handles non-interactive mode
 * @input: param to evaluate
 * Return: void
 */
void execute_non_interactive(char *input)
{
	char *parsed[MAXLIST];

	input[strcspn(input, "\n")] = 0;
	parse_non_interactive(input, parsed);

	if (cmd_handler(parsed) == 0)
	{
		pid_t pid = fork();
		if (pid == -1)
		{
			perror("fork failed");
			return;
		}
		if (pid == 0)
		{
			execve(parsed[0], parsed, NULL);
			perror("execve failed");
			exit(1);
		}
		else
		{
			wait(NULL);
		}
	}
}
