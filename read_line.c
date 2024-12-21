#include "shell.h"
/**
 * read_line - Reads input text
 *
 * Return: void.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t buffsize = 0;
	ssize_t nread = getline(&line, &buffsize, stdin);

	if (nread == -1)
	{
		if (errno == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("Error while reading the line from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
