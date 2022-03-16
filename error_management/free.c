#include "../includes/so_long.h"

void    free_tab(char **tab)
{
    int i;

    i = 0;
    if (!tab)
        return ;
    else
    {
        while (tab[i])
            free(tab[i++]);
        free(tab);
    }
}

void    free_tab_size(char **tab, int size)
{
    int i;

    i = 0;
    while (i <= size)
        free(tab[i++]);
    free(tab);
}