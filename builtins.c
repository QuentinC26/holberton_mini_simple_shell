#include "shell.h"

/**
 * handle_builtin - handle built-in commands
 * @args: tokenized args
 */
void handle_builtin(char **args)
{
	if (strcmp(args[0], "env") == 0)
	{
		extern char **environ;
		int i = 0;

		while (environ[i])
		{
			printf("%s\n", environ[i]);
			i++;
		}
	}
}
