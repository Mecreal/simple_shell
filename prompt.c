#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* display - just to display the prompt
*/

void display(void)
{
	int _write;

	_write = write(STDOUT_FILENO, "$ ", 2);
	if (_write == -1)
	{
		printf("Error");
		exit(EXIT_FAILURE);
	}
}
