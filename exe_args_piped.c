#include "shell.h"
/**
 * exe_args_piped - execute piped system commands
 * @parsed: first param
 * @parsed_pipe: second param
 * Return: void.
 */
void exe_args_piped(char **parsed, char **parsed_pipe)
{
	int pipefd[2];
	pid_t p1, p2;

	if (pipe(pipefd) < 0)
	{
		perror("Pipe failed");
		return;
	}

	p1 = fork();
	if (p1 < 0)
	{
		perror("Fork failed for the first process");
		return;
	}
	if (p1 == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);

		exe_args(parsed);
		exit(0);
	}
	else
	{
		p2 = fork();
		if (p2 < 0)
		{
			perror("Fork failed for second process");
			return;
		}
		if (p2 == 0)
		{
			close(pipefd[1]);
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);
			exe_args(parsed_pipe);
			exit(0);
		}
	}
	close(pipefd[0]);
	close(pipefd[1]);
	wait(NULL);
	wait(NULL);
}
