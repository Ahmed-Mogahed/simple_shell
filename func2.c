#include "shell.h"

/**
 * which - searches directories in PATH variable for a command
 * @comm: command to search for
 * @fpath: full path of the command to execute
 * @path: full PATH variable
 * Return: pointer to full_path
 */
char *which(char *comm, char *fpath, char *path)
{
    unsigned int comm_length, path_length;
    char *path_copy, *token;

    comm_length = _strlen(comm);
    path_length = _strlen(path);

    /* Create a copy of the PATH variable and check if it exists */
    path_copy = malloc(sizeof(char) * path_length + 1);
    if (path_copy == NULL)
    {
        errs(3);
        return (NULL);
    }

    _strcpy(path_copy, path);

    token = strtok(path_copy, ":");
    while (token != NULL)
    {
        path_length = _strlen(token);
        fpath = malloc(sizeof(char) * (path_length + comm_length) + 2);
        if (fpath == NULL)
        {
            errs(3);
            return (NULL);
        }

        _strcpy(fpath, token);
        fpath[path_length] = '/';
        _strcpy(fpath + path_length + 1, comm);
        fpath[path_length + comm_length + 1] = '\0';

        if (access(fpath, X_OK) != 0)
        {
            free(fpath);
            fpath = NULL;
            token = strtok(NULL, ":");
        }
        else
            break;
    }

    free(path_copy);
    return (fpath);
}

