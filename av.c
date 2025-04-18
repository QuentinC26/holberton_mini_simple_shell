#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - the code
 * Return: 0
 */

int main(void)
{
	size_t chars_read = 0;
	char *line = NULL;
	char *token = NULL;
	char *sep = " \n";
	size_t buff_len = 0;
	char **array = NULL;
	int len = 0;
	int count = 0;

	/* affiche le prompt pour l'utilisateur*/
	printf("$ ");

	/*Il lit le texte de l'entrée standard (ce qu'on écrit au clavier) */
	chars_read = getline(&line, &buff_len, stdin);
	if (chars_read == -1)
	{
		free(line);
		return (1);
	}

	/*alloue de la mémoire pour le tableau de tokens*/
	array = malloc(sizeof(char *) * chars_read);
	if (array == NULL)
	{
		return (1);
	}

	/*Séparer le premier token grâce à strtok*/
	token = strtok(line, sep);
	len = strlen(token);
	array[0] = malloc(len + 1);
	strcpy(array[0], token);

	/*Boucle pour récupérer les autres tokens*/
	for (token = strtok(NULL, sep), count = 1; token != NULL; token = strtok(NULL, sep), count++)
	{
		len = strlen(token);
		array[count] = malloc(len + 1);
		strcpy(array[count], token);
	}

	/*Il affiche tout les tokens stockés */
	for (count = 0; array[count]; count++)
	{
		printf("array [%d] = %s\n", count, array[count]);
	}

	/*Il libère la mémoire*/
	free(line);
	return (count);
}
