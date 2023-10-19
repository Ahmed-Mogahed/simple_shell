#ifndef MYSHELL_H
#define MYSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;


char **get_c_args(char *u_input);
char *get_thecomm_path(char *comm);
char *get_the_user_input(void);

int myshell_built(char *comm);

void print_myshell_prompt(void);

void execute_myshell_command(char *_input);
void main_exe_command(char *comm, char **args);
void exe_exte_comman(char *comman, char **args);
void execute_extern_h(char *comm, char **args);
void execute_kid_process(char *com_path, char **args);

void free_args(char **args);


#endif /* MYSHELL */
