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

void    free_all(t_vars *vars)
{
    free_tab(vars->map->map);
    free_tab(vars->map->mini);
    free(vars->map);
    free(vars->pos);
    free(vars);
}