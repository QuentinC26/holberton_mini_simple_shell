#include "shell.h"

/**
 * _strtok - tokenize a string
 * @str: string to split
 * @delim: delimiters
 * Return: next token or NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *buffer;
	char *start;

	if (str != NULL)
		buffer = str;
	if (buffer == NULL)
		return (NULL);

	/* skip delimiters */
	while (*buffer && strchr(delim, *buffer))
		buffer++;

	if (*buffer == '\0')
		return (NULL);

	start = buffer;
	while (*buffer && !strchr(delim, *buffer))
		buffer++;

	if (*buffer)
	{
		*buffer = '\0';
		buffer++;
	}

	return (start);
}
