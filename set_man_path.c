#include "shell.h"
/**
 * set_manpath - sets the path for man
 * Return: void.
 */
void set_manpath(void)
{
	setenv("MANPATH", "/usr/bin/man", 1);
}
