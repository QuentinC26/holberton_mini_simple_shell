#include "shell.h"

/**
 * find_path - find full path of a command
 * @command: the command name
 * Return: full path if found, else original command
 */
char *find_path(char *command)
{
	char *path = getenv("PATH");
	static char full[1024];
	char *token;

	if (access(command, X_OK) == 0)
		return (command);

	token = _strtok(path, ":");
	while (token != NULL)
	{
		snprintf(full, sizeof(full), "%s/%s", token, command);
		if (access(full, X_OK) == 0)
			return (full);
		token = _strtok(NULL, ":");
	}
	return (command); /* fallback */
}
