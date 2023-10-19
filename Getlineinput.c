#include "myshell.h"

/**
 * get_the_user_input - Read input from the user
 *
 * Return: A dynamic allocated input str
 */

char *get_the_user_input(void)
{
	char *_input = NULL;
	ssize_t b_read;
	size_t len = 0;

	b_read = getline(&_input, &len, stdin);
	if (b_read == -1)
	{
		free(_input);
		return (NULL);
	}

	if (_input[b_read - 1] == '\n')
	{
		_input[b_read - 1] = '\0';
	}
	return (_input);
}

/**
 * print_myshell_prompt - Display the shell prompt
 */

void print_myshell_prompt(void)
{
	if (isatty(fileno(stdin)))
	{
		printf("$ ");
		fflush(stdout);
	}
}
