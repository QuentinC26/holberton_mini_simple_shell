#include "shell.h"

/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char **args;
	pid_t pid;
	int status;
    extern char **environ;

	while (1)
	{
		printf("$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;

		line[strcspn(line, "\n")] = '\0';
		args = parse_line(line);

		if (args[0] == NULL)
			continue;

		/* built-in check */
		if (strcmp(args[0], "exit") == 0)
			break;

		handle_builtin(args);

		pid = fork();
		if (pid == 0)
		{
			char *cmd_path = find_path(args[0]);
			if (execve(cmd_path, args, environ) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
	}

	free(line);
	return (0);
}
