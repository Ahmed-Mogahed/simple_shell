#include "shell.h"

/**
 * free_all_memo - frees all malloc'd space at end of main loop
 * @toke_n: pointer to toke_n arr
 * @L: pointer to user input b_uffer
 * @fpath: pointer to full path
 * @flag: flag marking if full_path was malloc'd
 * Return: void
 */
void free_all_memo(char **toke_n, char *L, char *fpath, int flag)

{
	free(toke_n);
	free(L);
	if (flag == 1)
	free(fpath);
}

/**
 * free_dp - free double pointer
 * @arr: double pointer to free
 * @leng_th: leng_th of double pointer
 * Return: void
 */
void free_dp(char **arr, unsigned int leng_th)
{
    unsigned int i;

    i = 0;
    while (i < leng_th)
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}
