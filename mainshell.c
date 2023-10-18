#include "shell.h"

/**
 * Main c - the main function for the simple shell.
 * @ac: number of args
 * @av: args
 * Return: 0 always (done)
 */
int main(int ac, char **av)
{
	(void) av;
    char *L = NULL;
    char **com = NULL;
    int stat = 0;
    (void) ac;

    while (1)
    {
        L = readLine();
        if (L == NULL)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            return (stat);
        }

        com = tokenizer(L);
        if (!com)
            continue;
    }
}
