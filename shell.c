#include "shell.h"

/**
 * main - Entry Point for the program
 * Return: 0 on Success, -1 on Fail.
 */
<<<<<<< HEAD
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
=======
>>>>>>> c723c8f0abc0cdc081093488840e9264dd1d8898

int main(void)
{
	char command[1024];

	while (1)
	{
		read_command(command, 1024);
		execute(command);
	}
	return (0);
}
