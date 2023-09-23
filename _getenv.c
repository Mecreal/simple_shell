#include "shell.h"


/**
* _getenv - getenv
* @name: name of the variable
* Return: 0 if not match, 1 on failure
*/

char *_getenv(const char *name)
{
	int i = 0;
	char *key = NULL, *value = NULL;
	char *env_copy = NULL, *result = NULL;

	while (environ[i])
	{
		env_copy = strdup(environ[i]);
		if (!env_copy)
		{
			perror("strdup");
			return (NULL);
		}

		key = strtok(env_copy, "=");
		if (key && _strcmp((char *)name, key) == 0)
		{
			value = strtok((NULL), "");
			if (value)
			{
				result = _strdup(value);
			}
			free(env_copy);
			return (result);
		}
		free(env_copy);
		i++;
	}
	return (NULL);
}
