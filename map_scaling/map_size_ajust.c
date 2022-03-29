#include "../includes/so_long.h"

/*  Dans le cas ou la map est plus grande decouper un carre dans la map */

void    det_case_x(t_map *m, t_mv *p)
{
    if (m->len < 4)
        det_case_y(m, p, m->len);
    else if (m->len < 6)
        det_case_y(m, p, m->len);
    else if (m->len < 8)
        det_case_y(m, p, m->len);
    else if (m->len < 10)
        det_case_y(m, p, m->len);
    else if (m->len < 12)
        det_case_y(m, p, m->len);
    else if (m->len < 14)
        det_case_y(m, p, m->len);
    else if (m->len < 16)
        det_case_y(m, p, m->len);
    else if (m->len < 18)
        det_case_y(m, p, m->len);
    else if (m->len <= 20)
        det_case_y(m, p, m->len);
    else
        det_case_y(m, p, 20);
}

void    det_case_y(t_map *m, t_mv *p, int x)
{
    if (m->height < 4)
        ajust(m, p, x, m->height + 1);
    else if (m->height < 6)
        ajust(m, p, x, m->height + 1);
    else if (m->height < 8)
        ajust(m, p, x, m->height + 1);
    else if (m->height < 10)
        ajust(m, p, x, m->height + 1);
    else if (m->height < 12)
        ajust(m, p, x, m->height + 1);
    else if (m->height < 14)
        ajust(m, p, x, m->height + 1);
    else if (m->height < 16)
        ajust(m, p, x, m->height + 1);
    else if (m->height < 18)
        ajust(m, p, x, m->height + 1);
    else if (m->height <= 20)
        ajust(m, p, x, m->height);
    else
        ajust(m, p, x, 20);
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

void    ajust(t_map *m, t_mv *p, int x, int y)
{   
    int i;
    int j;

    j = (y / 2) * -1;
    i = 0;
    m->mini = malloc(sizeof(char *) * y + 1); // Nombre de ligne max a malloc + 1
    while (i < y - 1) // Prendre 6 lignes
    {
        if ((p->y + j) < 0) // Check si la ligne existe
            j++;
        else if ((p->y + j) > m->height - 1)
            j--;
        else 
        {
            m->mini[i] = str_cut(m->mini[i], m->map[p->y + j], p->x - (x / 2), p->x + (x / 2), m);
            j++;
            i++;
        }
    }
    m->mini[i] = NULL;
}
