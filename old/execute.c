#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * execute - that executes a command
 * @command: string holds the command.
 */

void execute(char command[])
{
	pid_t pid = fork();
	char *args[130];
	char *envp[] = {"USERNAME=amira", NULL};
	char *token = strtok((char *)command, " ");
	int status;
	int arg_count = 0;


	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;
		if (execve(command, args, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("wait");
			exit(EXIT_FAILURE);
		}
	}
}
