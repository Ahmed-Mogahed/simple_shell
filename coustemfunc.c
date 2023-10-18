#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void perr(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

int out(char *message) {
    write(STDOUT_FILENO, message, strlen(message));
    return 0;
}

char *_which(const char *file, const char *path) {
    char *full_path = NULL;
    char *token;
    char *path_copy = strdup(path);

    if (path_copy == NULL) {
        perr("Memory allocation error in _which");
    }

    token = strtok(path_copy, ":");

    while (token != NULL) {
        full_path = (char *)malloc(strlen(token) + strlen(file) + 2);

        if (full_path == NULL) {
            perr("Memory allocation error in _which");
        }

        strcpy(full_path, token);
        strcat(full_path, "/");
        strcat(full_path, file);

        if (access(full_path, F_OK) == 0) {
            free(path_copy);
            return full_path;
        }

        free(full_path);
        token = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}
