#include "shell.h"


/**
 * read_l - Entry point for the shell
 * @av: argument variable
 * Return: an array of tokens, 1 on failure
 */

char **read_l(char **av)
{
	char *buffer = NULL, **tokens = NULL;
	size_t size_buffer;
	unsigned int n_char = 0;

	if (isatty(0))
		write(1, "$ ", 2);
	n_char = getline(&buffer, &size_buffer, stdin);
	if (n_char == EOF)
	{
		free(buffer);
		return (NULL);
	}
	if (n_char > 0 && buffer[n_char - 1] == '\n')
	{
		buffer[n_char - 1] = '\0';
	}
	tokens = tokenize(buffer);

	if (!tokens)
	{
		perror(av[0]);
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (tokens);
}
