#include "myshell.h"

/**
 * free_args - Free memory allocated for command arguments
 * @args: Array of arguments
 *
 * This function frees memory allocated for command arguments.
 */

void free_args(char **args)
{
	int u;

	for (u = 0; args[u] != NULL; u++)
	{
		free(args[u]);
	}
	free(args);
}

/**
 * main – the main func for the program
 * @argc: The number of command-line arguments passed to the program.
 * @argv: An array of strings containing the actual command-line arguments.
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		int u;

		for (u = 1; u < argc; u++)
		{
			execute_myshell_command(argv[u]);
		}
	}
	else
	{
		char *_input;

		do {
			print_myshell_prompt();
			_input = get_the_user_input();

			if (_input != NULL)
			{
				if (strlen(_input) == 0)
				{
					free(_input);
					continue;
				}
				execute_myshell_command(_input);
				free(_input);
			}
			else
			{
				if (isatty(fileno(stdin)))
				{
					printf("\n");
				}
				exit(EXIT_SUCCESS);
			}
		} while (1);
	}
	return (0);
}
