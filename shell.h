#ifndef SHELL_H
#define SHELL_H

extern char **environ;


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void read_command(char command[], size_t size);
char **tokenize(char *str);
int ex(char **str, int status, char **v);
void execute(char command[]);
char **read_l(char **av);
char *_strcat(char *first, char *second);
int _strlen(char *str);
char *_strdup(char *str);
void _strcpy(char *dest, const char *src);
int _mat_clear(char **mat);

#endif /* SHELL_H */
