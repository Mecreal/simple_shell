#include "shell.h"


/**
 * main - Entry point for the shell
 * @ac: number of variable
 * @av: argument variable
 * @env: environment var
 * Return: 0 on success, 1 on failure
 */

int main(int ac, char **av)
{
	int status = 0;
	char **rlr = NULL;

	(void)ac;

	while (1)
	{
		rlr = read_l(av);
		if (!rlr)
		{
			if (isatty(0))
				write(1, "\n", 1);
			return (status);
		}
		if (rlr[0] == NULL || rlr[0][0] == '\0')
		{
			_mat_clear(rlr);
			continue;
		}
		ex(rlr, status, av);
		/*free(rlr), rlr = NULL;*/
	}
	return (0);
}
