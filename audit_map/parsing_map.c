#include "../includes/so_long.h"

void    get_map(int fd, t_map map)
{
    int     i;

    i = 0;
    while (get_next_line(fd) != NULL)
        map.map[i++] = ft_strdup(get_next_line(fd));
    map.map[i] = NULL;
    map.height = i - 1;
}

static void    border_analyzer(t_map map)
{
    int     i;
    int     j;
    int     len;

    j = 0;
    len = map.len - 1;
    i = 0;
    while (map.map[i] != '\n')
    {
        if (map.map[i][0] != '1' || map.map[i][len] != '1')
            end_program(ERROR_WALL);
        i++;
    }
    while (map.map[0] != '\n')
    {
        if (map.map[0][j++] != '1' || map.map[i - 1][j++] != '1')
            end_program(ERROR_WALL);
    }
    map.c_wall == 1;
}

static void    charac_analizer(t_map map, char *line)
{
    int     i;

    i = 0;
    while (line[i] != '\n')
    {
        if (line[i] == 'C')
            map.c_c += 1;
        if (line[i] == 'P' && map.c_p == 1)
            line[i] = '0';
        if (line[i] == 'B' && map.c_b == 1)
            line[i] = '0';
        else if (line[i] == 'P')
            map.c_p = 1;
        else if (line[i] == 'E')
            map.c_e = 1;
        else if (line[i] == 'B')
            map.c_b = 1;
        i++;
    }
}

void    audit(t_map map, t_mv pos)
{
    int     i;

    i = 0;
    map.len = ft_strlen(map.map[i]) - 1;
    while (map.map[i] != '\n')
    {
        init_pos(pos, map, map.map[i], i);
        charac_analyzer(map, map.map[i]);
        if ((ft_strlen(map.map[i]) - 1) !=  map.len)
            end_program(ERROR_OBLONG);
        i++;
    }
    border_analyzer(map);
    map.c_oblong == 1;
    if (map.len == i)
        end_program(ERROR_OBLONG);
    if (map.c_e == 1 && map.c_p == 1 && map.c_c == 1)
        map.c_init == 1;
    if (map.c_init != 1)
        end_program(ERROR_INIT);
}
