#include "shell.h"

/**
 * main - Entry point for the shell
 * @argc: Argument count
 * @argv: Argument vector
 * @env: Environment variables
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;

	shell_loop();
	return (0);
}
