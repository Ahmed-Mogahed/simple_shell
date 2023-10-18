#include "shell.h"
/**
*Main c -the main funcs for simple shell
*@ac: num of args
*@av: args
*Return: 0 always (done)
*/

int main (int ac, char **argv)
{
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
write(STDOUT_FILENO, “\n”, 1);
return (stat);
}

com = tokenizer(L);
if (!com)
	continue;
stat = _exe(com, argv);
}
}
