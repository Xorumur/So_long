#include "../includes/so_long.h"

void afftab(char **map)   
{
    int i;

    i = 0;
    while (map[i])
    {
        ft_putstr(map[i]);
        i++;
    }
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
        printf("%c", str[i++]);
}