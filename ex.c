#include "shell.h"


/**
 * handle_exit - Handles the exit command.
 * @tokens: The command tokens.
 * @status: The exit status to use.
 */
void handle_exit(char **tokens, int status)
{
	if (_strcmp(tokens[0], "exit") == 0)
	{
		_mat_clear(tokens);
		exit(status);
	}
}

/**
 * handle_exec - Executes the command.
 * @tokens: The command tokens.
 * @av: The argument variables.
 */
void handle_exec(char **tokens, char **av)
{
	if (execve(tokens[0], tokens, environ) == -1)
	{
		perror(av[0]);
		_mat_clear(tokens);
		exit(127);
	}
	if (!environ)
	{
		_mat_clear(tokens);
		exit(128);
	}
}

/**
 * handle_child_process - Handles the child process logic.
 * @tokens: The command tokens.
 * @status: The exit status.
 * @av: The argument variables.
 */
void handle_child_process(char **tokens, int status, char **av)
{
	if (tokens != NULL && tokens[0] != NULL)
	{
		if (_strcmp(tokens[0], "exit") == 0)
		{
			_mat_clear(tokens);
			exit(status);
		}

		if (!environ)
		{
			_mat_clear(tokens);
			exit(129);
		}
		handle_exec(tokens, av);
	}
	_mat_clear(tokens);
	exit(0);
}


/**
 * ex - Executes the command by forking and calling execve.
 * @tokens: The command tokens.
 * @exit_status: Pointer to the exit status.
 * @av: The argument variables.
 * Return: 0 on success, 1 on failure.
 */
int ex(char **tokens, int *exit_status, char **av)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		_mat_clear(tokens);
		return (1);
	}
	else if (pid == 0)
	{
		handle_child_process(tokens, *exit_status, av);
	} else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			*exit_status = WEXITSTATUS(status);
		}
		_mat_clear(tokens);
	}
	return (0);
}
