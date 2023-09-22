#include "shell.h"
/**
 * ex - execve the command
 *@tokens: Argument count
 *@status: is the status to be returned
 *@av: argument variable
 *@env: envirenement variable
 * Return: 0 on success, 1 on failure.
 */
int ex(char **tokens, int status, char **av, char **env)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		_mat_clear(tokens), tokens = NULL;
		return (1);
	}
	else if (!pid)
	{
		if (execve(tokens[0], tokens, env) == -1)
		{
			perror(av[0]);
			_mat_clear(tokens);
			exit(1);
		}
	}
	else
	{
		wait(&status);
		_mat_clear(tokens), tokens = NULL;
	}
	return (0);
}