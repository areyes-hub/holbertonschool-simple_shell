#include "shell.h"
/**
 * print_dir - prints the current directory
 * Return: void.
 */
void print_dir(void)
{
	char pwd[1024];

	getcwd(pwd, sizeof(pwd));
	printf("\n%s", pwd);
}
