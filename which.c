#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH 1024

void _which(char *filename) {
    char *path = getenv("PATH"); // Récupère la variable d'environnement PATH
    char *token;
    char fullpath[MAX_PATH];

    if (path == NULL) {
        printf("PATH not found.\n");
        return;
    }

    // Divise le PATH en utilisant ':' comme délimiteur
    token = strtok(path, ":");
    while (token != NULL) {
        // Construit le chemin complet du fichier
        snprintf(fullpath, sizeof(fullpath), "%s/%s", token, filename);
        
        // Vérifie si le fichier existe
        if (access(fullpath, F_OK) == 0) {
            printf("Found: %s\n", fullpath);
            return;
        }
        token = strtok(NULL, ":");
    }

    printf("File not found: %s\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: _which filename...\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        _which(argv[i]);
    }

    return 0;
}
