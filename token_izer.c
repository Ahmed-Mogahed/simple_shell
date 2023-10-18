#include "shell.h"

/**
 * token_izer - tokenizes string
 * @str: user input
 * Return: pointer to arr of toke_n
 */

char **token_izer(char *str)
{
	char **toke_n;
	char *token;
	unsigned int i;

	toke_n = malloc(sizeof(char) * B_UFFER);
	if (toke_n == NULL)
	{
		errs(3);
		exit(EXIT_FAILURE);
	}

	token = strtok(str, "\n\t\r ");

	i = 0;
	while (token != NULL)
	{
		toke_n[i] = token;
		token = strtok(NULL, "\n\t\r ");
		i++;
	}

	toke_n[i] = NULL;

	return (toke_n);
}
