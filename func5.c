#include "shell.h"

/* Declaration of the perr function */
void perr(const char *errmsg);

/**
 * errs - prints errors based on case
 * @err: error number associated with perr statement
 * Return: void
 */
void errs(int err)
{
    switch (err)
    {
    case 1: /* writes fork error to stderr */
        write(STDERR_FILENO, ERR_FORK, _strlen(ERR_FORK));
        perr("Err");
        break;

    case 2: /* writes execve error to stderr */
        perr("Err");
        break;

    case 3: /* writes malloc error to stderr */
        write(STDERR_FILENO, ERR_MALLOC, _strlen(ERR_MALLOC));
        break;
        
    case 4: /* writes empty path error to stderr */
        write(STDERR_FILENO, ERR_PATH, _strlen(ERR_PATH));
        break;

    default:
        return;
    }
}
