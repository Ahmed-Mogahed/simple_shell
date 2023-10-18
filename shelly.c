#include "shell.h"

/**
 * main - main of the shell
 * Return: 0 on success
 */

int main(void)
{
    char *L, *fpath, *path; /* Declare the 'path' variable.*/
    char **toke_n;
    int flag, builtin_status, kid_status;
    struct stat b_uf;

    while (TRUE)
    {
        promp_t(STDIN_FILENO, b_uf);
        L = _getL(stdin);
        if (_strcmp(L, "\n", 1) == 0)
        {
            free(L);
            continue;
        }
        toke_n = token_izer(L);
        if (toke_n[0] == NULL)
            continue;
        builtin_status = builtin_execute(toke_n);
        if (builtin_status == 0 || builtin_status == -1)
        {
            free(toke_n);
            free(L);
        }
        if (builtin_status == 0)
            continue;
        if (builtin_status == -1)
            _exit(EXIT_SUCCESS);
        flag = 0;
        path = _getenv("PATH"); /* Assign the value to the 'path' variable.*/
        fpath = _which(toke_n[0], path); /* Correct 'fpath' assignment*/
        if (fpath == NULL)
            fpath = toke_n[0];
        else
            flag = 1;
        kid_status = kid(fpath, toke_n);
        if (kid_status == -1)
            errs(2);
        free_all_memo(toke_n, L, fpath, flag); /* Update 'potath' to L*/
    }
    return (0);
}
