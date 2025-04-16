#include <stdlib.h>
#include "main.h"

int count_words(char *str)
{
    int i = 0, words = 0;

    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
        if (str[i])
            words++;
        while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            i++;
    }
    return words;
}

int word_len(char *str)
{
    int len = 0;
    while (str[len] && str[len] != ' ' && str[len] != '\t' && str[len] != '\n')
        len++;
    return len;
}

char **strtow(char *str)
{
    int j, k;
    int words, len;
    char **result;

    if (str == NULL || *str == '\0')
        return NULL;

    words = count_words(str);
    result = malloc(sizeof(char *) * (words + 1));
    if (result == NULL)
        return NULL;

    for (k = 0; k < words; k++)
    {
        while (*str == ' ' || *str == '\t' || *str == '\n')
            str++;

        len = word_len(str);
        result[k] = malloc(sizeof(char) * (len + 1));
        if (result[k] == NULL)
        {
            while (k > 0)
                free(result[--k]);
            free(result);
            return NULL;
        }

        for (j = 0; j < len; j++)
            result[k][j] = str[j];
        result[k][j] = '\0';

        str += len;
    }
    result[k] = NULL;
    return result;
}
