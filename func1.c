#include "shell.h"

/**
 * promp_t - checks mode and prints promp_t if in interactive mode
 * @f_d: file stream
 * @b_uf: b_uffer
**/
void promp_t(int f_d, struct stat b_uf)
{
	fstat(f_d, &b_uf);

	if (S_ISCHR(b_uf.st_mode))
		_puts(PROMP_T);
}

/**
 * _puts - prints a string without a \n
 * @str: string to print
 * Return: void
 */
void _puts(char *str)
{
	unsigned int leng_th;

	leng_th = _strlen(str);

	write(STDOUT_FILENO, str, leng_th);
}
