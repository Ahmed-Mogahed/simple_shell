#include "shell.h"

/* Declare the 'path' variable at the beginning of the file */
char *path;

/**
 * _getenv - gets an environment variable
 * @nam: environment variable to get
 * Return: pointer to environment variable or NULL if there is no match
 */
char *_getenv(const char *nam)
{
    char **environ_copy;
    char *vari, *v;
    int compare;
    unsigned int path_length, environ_length, length, i;

    environ_length = 0;
    while (environ[environ_length] != NULL)
        environ_length++;
    environ_copy = NULL;
    environ_copy = copy_env(environ_copy, environ_length);

    length = _strlen((char *)nam);
    i = 0;
    while (environ_copy[i] != NULL)
    {
        vari = environ_copy[i];
        compare = _strncmp((char *)nam, vari, length);
        if (compare == 1)
        {
            v = strtok(vari, "=");
            v = strtok(NULL, "\n ");
            if (v == 0)
            {
                errs(4);
                exit(EXIT_FAILURE);
            }
            path_length = _strlen(v);
            path = malloc(sizeof(char) * path_length + 1);
            if (path == NULL)
            {
                errs(3);
                return (NULL);
            }
            path = _strcpy(path, v);
            free_dp(environ_copy, environ_length);
            return (path);
        }
        i++;
    }
    return (NULL);
}

/**
 * copy_env - copies environment variable
 * @environ_copy: pointer to copy of environment variable
 * @environ_length: length of environment variable
 * Return: double pointer to copy of environment variable
 */
char **copy_env(char **environ_copy, unsigned int environ_length)
{
    char *vari;
    unsigned int vari_length;
    unsigned int i;

    environ_copy = malloc(sizeof(char **) * (environ_length));
    if (environ_copy == NULL)
    {
        errs(3);
        return (NULL);
    }

    i = 0;
    while (i < environ_length)
    {
        vari = environ[i];
        vari_length = _strlen(vari);

        environ_copy[i] = malloc(sizeof(char) * vari_length + 1);
        if (environ_copy[i] == NULL)
        {
            errs(3);
            return (NULL);
        }
        _strcpy(environ_copy[i], environ[i]);
        i++;
    }

    return (environ_copy);
}
