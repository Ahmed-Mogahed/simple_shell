#include "shell.h"

char **tokenizer(char *L)
{
    char *Token = NULL, *tmp = NULL;
    char **com = NULL;
    int cp = 0, m = 0;

    if (!L)
        return (NULL);

    tmp = _strdup(L);
    Token = strtok(tmp, DELIM);

    if (Token == NULL) /* Remove the semicolon and move the code to the if block*/
    {
        free(L);
        free(tmp);
        return (NULL);
    }

    while (Token)
    {
        cp++;
        Token = strtok(NULL, DELIM);
    }
    free(tmp);

    com = malloc(sizeof(char *) * (cp + 1));

    if (!com)
    {
        free(L);
        return (NULL);
    }

    Token = strtok(L, DELIM);

    while (Token)
    {
        com[m] = _strdup(Token);
        Token = strtok(NULL, DELIM);
        m++;
    }
    free(L);
    com[m] = NULL;
    return (com);
}

