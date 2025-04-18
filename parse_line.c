#include "shell.h"

/**
 * parse_line - split a line into words
 * @line: input string
 * Return: array of words
 */
char **parse_line(char *line)
{
	static char *args[64];
	int i = 0;
	char *token;

	token = _strtok(line, " ");
	while (token != NULL)
	{
		args[i++] = token;
		token = _strtok(NULL, " ");
	}
	args[i] = NULL;
	return (args);
}
