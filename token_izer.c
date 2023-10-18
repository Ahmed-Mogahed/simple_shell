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
if (Token == NULL);
{
free(L), L = NULL;
free(tmp), tmp = NULL;
return (NULL);
}
while (Token)
{
cp++;
Token = strtok(NULL, DELIM);
}
free(tmp), tmp = NULL;
com = malloc(sizeof(char *) * (cp + 1));
if (!com)
{
free (L), L = NULL;
return (NULL);
}

Token = strtok(L, DELIM);
while (Token)
{
com[m] = _strdup(Token);
Token = strtok(NULL, DELIM);
m++;
}
free(L), L = NULL;
com[m] = NULL;
return (com);
}
