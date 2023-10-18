#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define B_UFFER 1024
#define TRUE 1
#define PROMP_T "$ "
/* err strs */
#define ERR_MALLOC "Unable to malloc space\n"
#define ERR_FORK "Unable to fork and create kid process\n"
#define ERR_PATH "No such file or directory\n"
extern char **environ;

/**
 * struct l_ists - linked list of varis
 * @v: value
 * @after: pointer to after node
 *
 * Description: generic for varis.
 */

typedef struct l_ists
{
	char *v;
	struct l_ists *after;
} l_ists;

/**
 * struct b_uilt  - link list of builtin
 * @nam: nam of builtin
 * @p: pointer to function
 *
 * Description: struct for builtin functions.
 */

typedef struct b_uilt 
{
	char *nam;
	int (*point)(void);
} b_uilt ;

int out(char *L);
void C(int snum);
void pprom(void);
char *str_cat(char *str_1, char *str_2);
char *_cat(char *conca, char *str_1, char *str_2);
void promp_t(int f_d, struct stat b_uf);
char *_getL(FILE *fp);
char **token_izer(char *str);
char *which(char *comm, char *fpath, char *potath);
int kid(char *fpath, char **toke_n);
void errs(int err);
void _puts(char *str);
int _strlen(char *s);
int _strcmp(char *nam, char *vari, unsigned int leng_th);
int _strncmp(char *nam, char *vari, unsigned int leng_th);
char *_strcpy(char *dest, char *src);
int shell_env(void);
int shell_exit(void);
int builtin_execute(char **toke_n);
int shell_n_builti(b_uilt  builtin[]);
char *_getenv(const char *nam);
char **copy_env(char **environ_copy, unsigned int environ_leng_th);
l_ists *potathlist(char *vari, l_ists *head);
void free_all_memo(char **toke_n, char *L, char *fpath, int flag);
void free_dp(char **arr, unsigned int leng_th);
void perr(const char *message);
char *_which(const char *command, const char *path);

#endif
