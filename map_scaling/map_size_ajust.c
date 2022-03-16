#include "../includes/so_long.h"

/*  Dans le cas ou la map est plus grande decouper un carre dans la map */

// void    ajust(t_map *m, t_mv *p)
// {   
//     int i;

//     i = 0;
//     m->mini = malloc(sizeof(char *) * 7);
//     while (i <= 5)
//     {
//         m->mini[i] = str_cut(m->mini[i], m->map[p->y + i - 2], p->x - 4, p->x + 4, m);
//         i++;
//     }
//     m->mini[i] = NULL;
// }

void    ajust(t_map *m, t_mv *p)
{   
    int i;
    int j;

    j = 0;
    i = 0;
    m->mini = malloc(sizeof(char *) * 7); // Nombre de ligne max a malloc + 1
    while (i <= 5) // Prendre 6 lignes
    {
        if ((p->y + j - 2) < 0) // Check si la ligne existe
        {
            j++;
        }
        else 
        {
            m->mini[i] = str_cut(m->mini[i], m->map[p->y + j - 2], p->x - 4, p->x + 4, m);
            j++;
            i++;
        }
    }
    m->mini[i] = NULL;
}

char    *str_cut(char *dst, char *src, int  start, int end, t_map *map)
{
    int i;

    i = 0;
    dst = malloc((end - start + 2)* sizeof(*dst));
    while (start <= end) // Copie la ligne entre start et end et ajuste.
    {
        if (start < 0)
        {
            end++;
            start++;
        }
        else if (end > map->len)
        {
            start--;
            end--;
        }
        else
        {
            dst[i] = src[start];
            i++;
            start++;
        }
    }
    dst[i] = '\0';
    return (dst);
}