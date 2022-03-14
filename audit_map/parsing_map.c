#include "../includes/so_long.h"

void    get_map(int fd, t_map *map)
{
    int     i;
    char    *line;
    char    **tab;

    tab = malloc(sizeof(**tab));
    line = get_next_line(fd);
    i = 0;
    while (line != NULL)
    {
        tab[i++] = ft_strdup(line);
        line = get_next_line(fd);
    }
    tab[i] = NULL;
    map->map = tab;
    map->height = i;
}

static void    border_analyzer(t_map *map)
{
    int     i;
    int     j;
    int     len;

    j = 0;
    len = map->len - 1;
    i = 0;
    while (map->map[i])
    {
        if (map->map[i][0] != '1' || map->map[i][len] != '1')
            end_program(ERROR_WALL);
        i++;
    }
    if (map->map[0][j++] != '1' || map->map[i - 1][j++] != '1')
        end_program(ERROR_WALL);
    map->c_wall = 1;
}

static void    charac_analizer(t_map *map, char *line)
{
    int     i;

    i = 0;
    while (line[i] != 13 && line[i])
    {
        if (line[i] == 'C')
            map->c_c += 1;
        else if (line[i] == 'P' && map->c_p == 1)
            line[i] = '0';
        else if (line[i] == 'B' && map->c_b == 1)
            line[i] = '0';
        else if (line[i] == 'P')
            map->c_p = 1;
        else if (line[i] == 'E')
            map->c_e = 1;
        else if (line[i] == 'B')
            map->c_b = 1;
        else if (line[i] != '0' && line[i] != '1')
        {
            // printf("\n%i\n", line[i]);
            // printf("%c\n", line[i]);
            // printf("line %s\n", line);
            end_program(ERROR_BAD_CHAR);
        }
        i++;
    }
}

void    audit(t_map *map) //void    audit(t_map map, t_mv pos)
{
    int     i;

    i = 0;
    map->len = ft_strlen(map->map[i]) - 2;
    while (map->map[i])
    {
        // init_pos(pos, map, map.map[i], i);
        charac_analizer(map, map->map[i]);
        if ((ft_strlen(map->map[i]) - 2) !=  map->len)
            end_program(ERROR_OBLONG); 
        i++;
    }
    border_analyzer(map);
    map->c_oblong = 1;
    if (map->len == i)
        end_program(ERROR_OBLONG);         
    if (map->c_e == 1 && map->c_p == 1 && map->c_c > 0)
        map->c_init = 1;
    if (map->c_init != 1)
        end_program(ERROR_INIT);
}
