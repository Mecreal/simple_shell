#include "shell.h"

/**
 * main - Entry Point for the program
 * Return: 0 on Success, -1 on Fail.
 */

int main(void)
{
	char command[200];

	while (1)
	{
		display();
		read_command(command, sizeof(command));
		execute(command);
	}
	return (0);
}
