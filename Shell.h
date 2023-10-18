#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include >fcntl.h<

#define DELIM “ \t\n”

char *readLine(void);
char **tokenizer(char *L);
int _strlen(char *s)
char *_strdup(const char *str)
int _strcmp(char *s1, char *s2)
char *_strcat(char *dest, char *src)
char *_strcpy(char *dest, char *src)

#endif
