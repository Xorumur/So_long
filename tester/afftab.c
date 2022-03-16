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
    int len;

    len = ft_strlen(str) - 1;
    i = 0;
    while (str[i])
        printf("%c", str[i++]);
    if (str[len] != '\n')
        printf("\n");
}