#include "myshell.h"

/**
 * main_exe_command - Execute a main shell command
 * @comm: The command to execute
 * @args: Array of command arguments
 *
 * This function executes built-in shell commands like "exit" and "env".
 */

void main_exe_command(char *comm, char **args)
{
	if (strcmp(comm, "exit") == 0)
	{
		int ex = 0;

		if (args[1] != NULL)
			ex = atoi(args[1]);

		free_args(args);
		exit(ex);
	}
	else if (strcmp(comm, "env") == 0)
	{
		char **env = environ;

		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
	}
}

/**
 * execute_kid_process - Execute a child process
 * @com_path: The path to the command to execute
 * @args: The arguments for the command
 *
 * This function handles the execution of a child process.
 */

void execute_kid_process(char *com_path, char **args)
{
	pid_t child_pid;
	int stat;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		free_args(args);
		return;
	}

	if (child_pid == 0)
	{
		if (execve(com_path, args, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&stat);
}

/**
 * execute_extern_h - Execute an external command
 * @comm: The command to execute
 * @args: The arguments for the command
 *
 * This helper function executes external commands.
 */

void execute_extern_h(char *comm, char **args)
{
	char *o_path, *n_path, *c_path;

	o_path = getenv("PATH");
	n_path = malloc(strlen(o_path) + 3);

	if (n_path == NULL)
	{
		perror("malloc");
		free_args(args);
		return;
	}

	sprintf(n_path, ".:%s", o_path);
	setenv("PATH", n_path, 1);
	c_path = get_thecomm_path(comm);
	setenv("PATH", o_path, 1);
	free(n_path);

	if (c_path != NULL)
	{
		execute_kid_process(c_path, args);
		free(c_path);
	}
	else
		printf("%s: command not found\n", comm);
}

/**
 * exe_exte_comman - Execute an external command
 * @comman: The command to execute
 * @args: The arguments for the command
 *
 * This function executes external commands.
 */

void exe_exte_comman(char *comman, char **args)
{
	if (comman[0] == '/')
	{
		execute_kid_process(comman, args);
	}
	else
	{
		execute_extern_h(comman, args);
	}
}

/**
 * execute_myshell_command - Execute a  command
 * @_input: The user-provided input string
 *
 * This function executes a shell command based on user input.
 */

void execute_myshell_command(char *_input)
{
	char **args;
	char *c;

	if (_input == NULL)
	{
		return;
	}

	args = get_c_args(_input);
	if (args == NULL)
	{
		return;
	}

	c = args[0];

	if (myshell_built(c))
	{
		main_exe_command(c, args);
	}
	else
	{
		exe_exte_comman(c, args);
	}

	free_args(args);
}
