#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * read - it's responsible for the user input of the shell
 * @command: string holds the command.
 * @size: the size of the command in Bytes.
 */

void read_command(char command[], size_t size)
{
	printf("$ ");

	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			printf("Error while reading\n");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}
