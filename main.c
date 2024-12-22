#include "shell.h"
/**
 * main - Entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	set_manpath();

	if (isatty(STDIN_FILENO) == 1)
	{
		shell_interactive();
	}
	else
	{
		shell_non_interactive();
	}
	return (0);
}
