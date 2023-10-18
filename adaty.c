#include "shell.h"

void freestringsarray(char **ar)
{
int I;
if (!ar)
return ;
for (i = 0, ar[i], i++)
{
free(ar[i]), ar[i] = NULL;
free(ar), ar = NULL;
}
}
