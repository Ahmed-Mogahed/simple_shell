#include "myshell.h"

/**
 * get_thecomm_path - Get the whole path of a command
 * @comm: The command to search for
 *
 * Return: The full path of the command or NULL
 */

char *get_thecomm_path(char *comm)
{
	char *p_env = getenv("PATH");
	char *p_copy;
	char *to;
	char *c_path;

	p_copy = strdup(p_env);
	if (p_copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}

	to = strtok(p_copy, ":");
	while (to != NULL)
	{
		c_path = malloc(strlen(to) + strlen(comm) + 2);
		if (c_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		sprintf(c_path, "%s/%s", to, comm);
		if (access(c_path, X_OK) == 0)
		{
			free(p_copy);
			return (c_path);
		}
		free(c_path);
		to = strtok(NULL, ":");
	}
	free(p_copy);
	return (NULL);
}
