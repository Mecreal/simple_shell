#include "shell.h"

/**
 * main - Entry point for the shell program.
 *
 * Return: 0 on success, or exit status on error.
 */
int main(void)
{
	char *userinput = NULL;
	size_t nline = 0;
	ssize_t n;
	int interactive_mode = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive_mode)
		{
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		}

		n = getline(&userinput, &nline, stdin);

		if (n == -1)
		{
			if (feof(stdin))
			{
				if (interactive_mode)
				{
					write(STDOUT_FILENO, "\n", 1);
				}
				break;
			}
			perror("getline");
			exit(EXIT_FAILURE);
		}

		if (_strcmp(userinput, "exit\n") == 0)
		{
			free(userinput);
			exit(EXIT_SUCCESS);
		}
		else if (_strcmp(userinput, "env\n") == 0)
		{
			_print_env();
		}
		else
		{
			if (call_fork(userinput, n) == 1)
			{
				_exec_cmd(userinput, n);
			}
		}
	}

	free(userinput);
	return (0);
}
