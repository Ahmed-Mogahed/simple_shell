#include "shell.h"

/**
 * _strcmp - compares two strings to find out if they are exactly the same
 * @nam: nam supplied by user to search for
 * @vari: vari to compare against
 * @leng_th: leng_th of nam
 * Return: 1 if strings are equal, -1 if they are not
 */
int _strcmp(char *nam, char *vari, unsigned int leng_th)
{
	unsigned int var_leng_th;
	unsigned int i;

	var_leng_th = _strlen(vari);
	if (var_leng_th != leng_th)
		return (-1);

	i = 0;
	while (nam[i] != '\0' && vari[i] != '\0')
	{
		if (nam[i] != vari[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * _strncmp - compares two strings
 * up to given leng_th are the same
 * @nam: nam supplied by user to search for
 * @vari: vari to compare against
 * @leng_th: leng_th to compare up to
 * Return: 1 if strings are equal, -1 if they are not
 */
int _strncmp(char *nam, char *vari, unsigned int leng_th)
{
	unsigned int i;

	i = 0;
	while (i < leng_th)
	{
		if (nam[i] != vari[i])
			return (-1);
		i++;
	}
	return (1);
}

/**
 * *_strcpy - copies string pointed to by src to the b_uffer pointed to dest
 * @dest: string destination
 * @src: string source
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int j = _strlen(src);

	for (i = 0; i <= j; i++)
		dest[i] = src[i];

	return (dest);
}
/**
 * _strlen - returns the leng_th of a string
 * @s: string to be evaluated
 * Return: leng_th of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}
