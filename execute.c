#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * execute - that executes a command
 * @command: string holds the command.
 */

void execute(char *command)
{
	pid_t pid = fork();
	char *args[2];
	char *envp[] = {NULL};
	int status;

       	args[0] = command;
	args[1] = NULL;

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0)
	{
		if (execve(command, args, envp) == -1) /* we treat the command as programPATH here */
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
