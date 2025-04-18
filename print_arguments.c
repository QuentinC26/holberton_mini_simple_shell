#include <stdio.h>

int main(int argc, char *argv[])
{
    char **arg;

    for (arg = argv + 1; *arg != NULL; arg++)
    {
        printf("%s\n", *arg);
    }

    return 0;

}