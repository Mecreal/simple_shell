#include "shell.h"


/**
 * tokenize - Entry point for the shell
 * @str: Argument count
 * Return: an array of tokens, 1 on failure
 */


char **tokenize(char *str)
{
	char *token, **tokens = NULL;
	int count = 0;
	char *delim = " \n\t\r\a\v";
	char *n_str;

	n_str = _strdup(str);

	for (token = strtok(n_str, delim); token; token = strtok(NULL, delim))
	{
		tokens = realloc(tokens, (count + 1) * sizeof(char *));
		if (!tokens)
		{
			free(n_str), n_str = NULL;
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		tokens[count] = _strdup(token);
		count++;
	}
	tokens = realloc(tokens, (count + 1) * sizeof(char *));
	tokens[count] = NULL;
	free(n_str), free(token);
	return (tokens);
}
