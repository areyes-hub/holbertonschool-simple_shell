#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <fcntl.h>
#include <errno.h>

#define MAXCOM 1000
#define MAXLIST 100

int handle_cd(char **parsed);
int prompt_line(char *str);
void print_env(void);
void print_dir(void);
void execute_non_interactive(char *input);
void exe_args(char **parsed);
void parse_non_interactive(char *input, char **parsed);
void exe_args_piped(char **parsed, char **parsed_pipe);
int cmd_handler(char **parsed);
int parse_pipe(char *str, char **str_piped);
void parse_space(char *str, char **parsed);
int process_string(char *str, char **parsed, char **parsed_pipe);

#endif
