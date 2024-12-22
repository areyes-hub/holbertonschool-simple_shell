#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

#define TOK_DELIM " \t\r\n\a"

extern char **environ;

void shell_interactive(void);
void shell_non_interactive(void);
char *read_line(void);
char **split_line(char *line);
int execute_args(char **args);
int new_process(char **args);
char *read_stream(void);
int _getchar(void);
int own_cd(char **args);
int own_exit(char **args);
int own_env(char **args);
int own_help(char **args);
int _atoi(char *str);
void set_manpath(void);

#endif
