#include "shell.h"

/**
 * kid - function for kid process
 * @fpath: full path of executable
 * @toke_n: tokenized user input
 * Return: 0 on success
 */
int kid(char *fpath, char **toke_n)
{
	pid_t kid_pid;
	int status;
	int execve_status;
	char **envp = environ;

	kid_pid = fork();
	if (kid_pid == -1)
	{
		errs(1);
		exit(EXIT_FAILURE);
	}
	if (kid_pid == 0)
	{
		execve_status = execve(fpath, toke_n, envp);
		if (execve_status == -1)
			return (-1);
	}
	else
		wait(&status);

	return (0);
}
