#include "shell.h"

/**
 * _getL - puts input from user into buffer L
 * @fp: file pointer for user input
 * Return: buffer with user input
 */
char *_getL(FILE *fp)
{
    char *L = NULL;
    size_t len = 0;
    ssize_t read;

    read = getline(&L, &len, fp);

    if (read == EOF || read == -1)
    {
        free(L);
        out(L);
        exit(EXIT_SUCCESS);
    }

    return (L);
}
