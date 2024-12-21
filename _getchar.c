#include "shell.h"
/**
 * _getchar - gets a single character
 * Return: A single character.
 */
int _getchar(void)
{
	char c;
	ssize_t result = read(STDIN_FILENO, &c, 1);

	if (result == -1)
	{
		perror("error reading from stdin");
		return (EOF);
	}
	else if (result == 0)
		return (EOF);
	return ((unsigned char)c);
}
