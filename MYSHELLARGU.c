#include "myshell.h"

/**
 * get_c_args - split the input into args
 * @u_input: The input string from the user
 *
 * Return: An array of arguments
 */

char **get_c_args(char *u_input)
{
	char **args = NULL;
	char *to;
	int arg_c = 0;

	to = strtok(u_input, " ");
	while (to != NULL)
	{
		args = realloc(args, (arg_c + 1) * sizeof(char *));
		if (args == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		args[arg_c] = strdup(to);
		if (args[arg_c] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		arg_c++;
		to = strtok(NULL, " ");
	}
	args = realloc(args, (arg_c + 1) * sizeof(char *));
	if (args == NULL)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}
	args[arg_c] = NULL;
	return (args);
}

/**
 * myshell_built - Check if a command is a built command
 * @comm: The command to check
 *
 * Return: 1 if built-in, 0 if not
 */

int myshell_built(char *comm)
{
	if (comm != NULL)
	{
		if (strcmp(comm, "exit") == 0 || strcmp(comm, "env") == 0)
		{
			return (1);
		}
	}
	return (0);
}
