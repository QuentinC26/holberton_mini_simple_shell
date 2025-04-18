#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_path_dirs(void)
{
    char *path = getenv("PATH");
    if (!path) {
        printf("PATH variable not found.\n");
        return;
    }

    // On fait une copie car strtok modifie la chaîne
    char *path_copy = strdup(path);
    if (!path_copy) {
        perror("strdup");
        return;
    }

    char *token = strtok(path_copy, ":");
    while (token) {
        printf("%s\n", token);
        token = strtok(NULL, ":");
    }

    free(path_copy);
}

int main(void)
{
    print_path_dirs();
    return 0;
}
