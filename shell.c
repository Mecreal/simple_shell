#include "shell.h"

/**
 * shell_loop - Main loop for the shell
 * Return: Null
 */
void shell_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("($) ");
		line = read_line();
		args = split_line(line);
		status = execute(args);

		free(line);
		free(args);
	} while (status);
}

/**
 * read_line - Reads a line from stdin
 * Return: The line from stdin
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	/*ssize_t n;*/

	getline(&line, &len, stdin);


	return (line);
}

/**
 * split_line - Splits a line into words
 * @line: The line
 * Return: Null-terminated array of words
 */
char **split_line(char *line)
{
	int bufsize = 64, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * execute - Executes a command
 * @args: Null-terminated array of arguments
 * Return: 1 if the shell should continue, 0 if it should terminate
 */
int execute(char **args)
{
	pid_t pid;
	int status;

	if (strcmp(args[0], "exit") == 0)
		return (0);

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			perror("error");
		exit(EXIT_FAILURE);
	} else if (pid < 0)
	{
		perror("error");
	} else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
