#include <stdio.h>

/**
 * main - the code
 * Return: 0
 */

int main(void)
{
	ssize_t chars_read = 0;
	char *line = NULL;
	size_t buff_len = 0;

	printf("$ ");
	chars_read = getline(&line, &buff_len, stdin);
	if (chars_read == -1)
	{
		printf("EOF\n");
	}
	else
	{
		printf("%s", line);
	}
	return (0);
}
