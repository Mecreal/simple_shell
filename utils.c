#include "shell.h"

/**
 * _mat_clear - copies the string pointed to by src to dest
 * @mat: the destination string
 * Return: 0 success 1 fail
 */


int _mat_clear(char **mat)
{
	int count = 0;

	if (!mat)
		return (1);

	while (mat && mat[count])
	{
		free(mat[count]);
		count++;
	}
	free(mat);
	return (0);
}
