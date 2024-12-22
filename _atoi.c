#include "shell.h"
/**
 * _atoi - converts alpha to integer
 * @str: character to convert
 * Return: Converted character.
 */
int _atoi(char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			fprintf(stderr, "Invalid number: %s\n", str);
			exit(EXIT_FAILURE);
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
