#include "shell.h"
/**
 * split_line - split a string into multiple strings
 * @line: string to split
 * Return: A pointer to the new array.
 */
char **split_line(char *line)
{
	int buffsize = 64, i = 0, j;
	char **tokens = malloc(buffsize * sizeof(char *));
	char **new_tokens;
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "allocation error in split_line: tokens\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		if (token[0] == '#')
			break;
		if (i >= buffsize)
		{
			buffsize *= 2;
			new_tokens = malloc(buffsize * sizeof(char *));
			if (!new_tokens)
			{
				fprintf(stderr, "allocation error in split_line: new_tokens\n");
				exit(EXIT_FAILURE);
			}
			for (j = 0; j < i; j++)
			{
				new_tokens[j] = tokens[j];
			}
			free(tokens);
			tokens = new_tokens;
		}
		tokens[i] = token;
		i++;
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}
