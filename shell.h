#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

char **parse_line(char *line);
char *_strtok(char *str, const char *delim);
char *find_path(char *command);
void handle_builtin(char **args);

#endif
