#include "shell.h"

/**
 * main - Entry Point for the program
 * Return: 0 on Success, -1 on Fail.
 */

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
