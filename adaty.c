#include "shell.h"

void freestringsarray(char **ar) {
    if (!ar)
        return;
    
    for (int i = 0; ar[i]; i++) {
        free(ar[i]);
        ar[i] = NULL;
    }
    
    free(ar);
    ar = NULL;
}
