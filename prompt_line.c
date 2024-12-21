#include "shell.h"
/**
 * prompt_line - Takes input
 * @str: input string
 * Return: On success, 0. Else, 1.
 */
int prompt_line(char *str)
{
	size_t len = 0;
	ssize_t read;
	char *buff = NULL;

	if (!isatty(STDIN_FILENO))
	{
		read = getline(&buff, &len, stdin);
		if (read == -1)
		{
			free(buff);
			return (1);
		}
		if (strlen(buff) != 0)
		{
			strcpy(str, buff);
			free(buff);
			return (0);
		} free(buff);
		return (1);
	}
	while (1)
	{
		printf(":) ");
		read = getline(&buff, &len, stdin);
		if (read == -1)
		{
			free(buff);
			return (1);
		}
		if (buff[read - 1] == '\n')
			buff[read - 1] = '\0';
		if (strlen(buff) != 0)
		{
			strcpy(str, buff);
			free(buff);
			return (0);
		}
		else if (strlen(buff) == 0)
			continue;
	} free(buff);
}
