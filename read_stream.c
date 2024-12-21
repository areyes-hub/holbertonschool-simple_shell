#include "shell.h"
/**
 * read_stream - read a line from the stream
 * Return: A pointer to the read line
 */
char *read_stream(void)
{
	int buffsize = 1024, i = 0, j;
	char *line = malloc(buffsize * sizeof(char *)), *new_line;
	int character;

	if (line == NULL)
	{
		fprintf(stderr, "allocation error in read_stream\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		character = _getchar();
		if (character == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		} else if (character == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		line[i] = character;
		i++;
		if (i >= buffsize)
		{
			buffsize *= 2;
			new_line = malloc(buffsize * sizeof(char));
			if (new_line == NULL)
			{
				fprintf(stderr, "allocation error in read_stream (new buffer)\n");
				free(line);
				exit(EXIT_FAILURE);
			}
			for (j = 0; j < i; j++)
				new_line[j] = line[j];
			free(line);
			line = new_line;
		}
	}
}
