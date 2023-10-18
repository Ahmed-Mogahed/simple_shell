#include "shell.h"

/**
 * builtin_execute - executes the built-in functions
 * @toke_n: arguments being passed
 * Return: Status code from the built-in function
 */
int builtin_execute(char **toke_n)
{
    int status;
    unsigned int leng_th;
    unsigned int num;
    unsigned int i;

    b_uilt builtin[] = {
        {"exit", shell_exit},
        {"env", shell_env},
        {NULL, NULL}
    };

    if (toke_n[0] == NULL)
        return (1);

    leng_th = _strlen(toke_n[0]);

    num = shell_n_builti(builtin);
    for (i = 0; i < num; i++)
    {
        if (_strcmp(toke_n[0], builtin[i].nam, leng_th) == 0)
        {
            status = (builtin[i].point)();
            return (status);
        }
    }
    return (1);
}

/**
 * shell_n_builti - count the number of built-in functions
 * @builtin: the array of built-ins
 * Return: Number of built-in functions
 */
int shell_n_builti(b_uilt builtin[])
{
    unsigned int i;

    i = 0;
    while (builtin[i].nam != NULL)
        i++;

    return (i);
}
