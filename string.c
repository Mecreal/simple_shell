#include "shell.h"


/**
* _strcpy - copies the string pointed to by src to dest
* @dest: the destination string
* @src: the source string
*/

void _strcpy(char *dest, const char *src)
{
	while ((*dest = *src))
	{
		dest++;
		src++;
	}
}

/**
* _strcat - concatenates two string in a path form
* @first: the first given destination
* @second: the second given source
*
* Return: (Success) a pointer to the newly concatenated string
* ------- (Fail) NULL if memory allocation fails
*/

char *_strcat(char *first, char *second)
{
	int len1 = _strlen(first);

	int len2 = _strlen(second);

	char *result = malloc(len1 + len2 + 2);

	if (!result)
		return (NULL);

	_strcpy(result, first);
	result[len1] = '/';
	_strcpy(result + len1 + 1, second);
	return (result);
}



/**
* _strlen - finds the length of a given string
* @str: the given string
*
* Return: (Success) the length of the string
* ------- (Fail) negative value
*/
int _strlen(char *str)
{
	int len;

	for (len = 0; str[len]; len++)
		;
	return (len);
}

/**
* _strdup - dupicates string
* @str: the given string
*
* Return: (Success) a pointer to the duplicated string
* ------- (Fail) return a null pointer
*/
char *_strdup(char *str)
{
	char *dupl;

	if (!str)
		return (NULL);
	dupl = malloc(_strlen(str) + 1);
	if (!dupl)
		return (NULL);
	_strcpy(dupl, str);
	return (dupl);
}


/**
* _strcmp - compare string
* @s1: the given string
* @s2: the given string 2
*
* Return: (Success) a pointer to the duplicated string
* ------- (Fail) return a null pointer
*/
int _strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (1);

	while (*s1 && (*s1 == *s2))
	{
		++s1;
		++s2;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
