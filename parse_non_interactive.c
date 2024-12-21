#include "shell.h"
/**
 * parse_non_interactive - parses input
 * in non-interactive mode
 * @input: first param
 * @parsed: second param
 * Return: void.
 */
void parse_non_interactive(char *input, char **parsed)
{
	int i = 0;
	char *token;
	char temp[MAXLIST];
	int in_quotes = 0;

	while ((token = strsep(&input, " ")) != NULL)
	{
		if (token[0] == '"' && token[strlen(token) - 1] == '"')
		{
			token[strlen(token - 1)] = '\0';
			token++;
		}
		else if (token[0] == '"')
		{
			in_quotes = 1;
			strcpy(temp, token + 1);
		}
		else if (in_quotes)
		{
			strcat(temp, " ");
			strcat(temp, token);
		}
		if (in_quotes && token[strlen(token) - 1] == '"')
		{
			in_quotes = 0;
			temp[strlen(temp) - 1] = '\0';
			parsed[i++] = strdup(temp);
		}
		else if (!in_quotes && strlen(token) > 0)
		{
			parsed[i++] = token;
		}
		if (i >= MAXLIST)
		{
			fprintf(stderr, "Error: too many arguments, MAXLIST reached\n");
			break;
		}
	}
	parsed[i] = NULL;
}
