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
		free(mat[count]), mat[count] = NULL;
		count++;
	}
	free(mat), mat = NULL;
	return (0);
}



/**
 * safe_free - copies the string pointed to by src to dest
 * @ptr: the destination string
 * Return: 0 success 1 fail
 */
void safe_free(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

