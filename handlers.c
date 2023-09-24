#include "shell.h"


/**
* path_handler - Builds a linked list of PATH directories
* @input: its the variable env
* Return: Pointer to the head of the linked list
*/
char *path_handler(char *input)
{
	char *path, *token, *new_node;

	struct stat st;
	char *result;


	path = _getenv("PATH");
	if (!path)
	{
		return (NULL);
	}

	token = strtok(path, ":");
	while (token)
	{
		new_node = build(input, token);


		if (!stat(new_node, &st))
		{
			result = _strdup(new_node);
			free(new_node);
			free(path);
			return (result);
		}
		free(new_node);
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}


/**
* build - Build Command
* @input: input Command
* @dir: dir of path
*
* Return: Another thing
*/
char *build(char *input, char *dir)
{
	char *cmd, *temp;

	size_t len;

	if (input == NULL || dir == NULL)
	{
		return (NULL);
	}
	len = _strlen(dir) + _strlen(input) + 2;
	cmd = malloc(sizeof(char) * len);
	if (!cmd)
		return (NULL);

	memset(cmd, 0, len);

	temp = _strcat(cmd, dir);
	free(cmd);
	cmd = temp;

	temp = _strcat(cmd, "/");
	free(cmd);
	cmd = temp;

	temp = _strcat(cmd, input);
	free(cmd);
	cmd = temp;
	return (cmd);
}


/**
* handle_builtin - Build Command
* @commandArgs: input Command
* @exit_status: exit_status
*
* Return: Another thing
*/

int handle_builtin(char **commandArgs, int *exit_status)
{
	int i = 0;

	if (strcmp(commandArgs[0], "exit") == 0)
	{
		if (commandArgs[1])
		{
			*exit_status = _atoi(commandArgs[1]);
		}
		_mat_clear(commandArgs);
		exit(*exit_status);
	}
	else if (strcmp(commandArgs[0], "env") == 0)
	{
		while (environ[i])
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
		return (1);
	}


	return (0);
}
