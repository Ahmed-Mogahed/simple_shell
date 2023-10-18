#include "shell.h"

char *readLine(void)
{
char *L = NULL;
size_t LEN = 0;
ssize_t N;

if (isatty(STDIN_FILENO))

	write(STDOUT_FILENO, "(; ", 2);
	N = getline(&L, &LEN stdin);
if (N == -1)
{
free(L);
return (NULL);
}

return (L);
}
