#include "shell.h"
/**
 * parse_space - for parsing command words
 * @str: first param
 * @parsed: second param
 * Return: void.
 */
void parse_space(char *str, char **parsed)
{
	int i = 0, in_quotes = 0;
	char *token, temp[MAXLIST];

	token = strsep(&str, " ");
	if (token != NULL && strlen(token) > 0)
	{
		parsed[i++] = token;
	}
	while ((token = strsep(&str, " ")) != NULL)
	{
		if (token[0] == '"' && token[strlen(token) - 1] == '"')
		{
			token[strlen(token) - 1] = '\0';
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
			parsed[i++] = token;
		if (i >= MAXLIST)
		{
			fprintf(stderr, "Error: too many arguments, MAXLIST reached\n");
			break;
		}
	}
	parsed[i] = NULL;
}
