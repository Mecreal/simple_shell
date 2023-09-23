#include "shell.h"


/**
 * main - Entry point for the shell
 * @ac: number of variable
 * @av: argument variable
 * Return: 0 on success, 1 on failure
 */

int main(int ac, char **av)
{
	int exit_status = 0;
	char **commandArgs = NULL;
	char *fullCommandPath = NULL;

	(void)ac;

	while (1)
	{
		commandArgs = read_l(av);
		if (!commandArgs)
		{
			if (isatty(0))
				write(1, "\n", 1);
			_mat_clear(commandArgs);
			free(fullCommandPath);
			return (0);
		}
		if (commandArgs[0] == NULL || commandArgs[0][0] == '\0')
		{
			_mat_clear(commandArgs);
			continue;
		}
		if (handle_builtin(commandArgs, &exit_status))
		{
			_mat_clear(commandArgs);
			free(fullCommandPath);
			continue;
		}
		free(fullCommandPath);
		fullCommandPath = path_handler(commandArgs[0]);

		if (fullCommandPath)
		{
			free(commandArgs[0]);
			commandArgs[0] = strdup(fullCommandPath);
		}
		ex(commandArgs, &exit_status, av);
		free(fullCommandPath);
		fullCommandPath = NULL;
	}
	free(fullCommandPath);
	return (exit_status);
}
