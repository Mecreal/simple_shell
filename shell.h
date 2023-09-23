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
int ex(char **str, int *status, char **v);
void execute(char command[]);
char **read_l(char **av);
char *_strcat(char *first, char *second);
int _strlen(char *str);
char *_strdup(char *str);
void _strcpy(char *dest, const char *src);
int _mat_clear(char **mat);
char *_getenv(const char *name);
int _strcmp(char *s1, char *s2);
char *path_handler(char *env_var);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
char *build(char *token, char *dir);
void handle_exit(char **tokens, int status);
void handle_exec(char **tokens, char **av);
void handle_child_process(char **tokens, int status, char **av);
int handle_builtin(char **commandArgs, int *exit_status);



#endif /* SHELL_H */
