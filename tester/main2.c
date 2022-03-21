#include "../includes/so_long.h"

t_map *init_map(void)
{
    t_map   *map;

    map = malloc(sizeof(t_map));
    map->len = 0;
    map->c_init = 0;
    map->c_e = 0;
    map->c_p = 0;
    map->c_c = 0;
    map->c_b = 0;
    map->c_oblong = 0;
    map->c_wall = 0;
    map->key = 0;
    return (map);
}

t_mv    *init_mv(void)
{
    t_mv    *pos;

    pos = malloc(sizeof(t_mv));
    pos->x = 0;
    pos->y = 0;
    pos->tmp_x = 0;
    pos->tmp_y = 0;
    pos->count = 0;
    pos->e_x = -1;
    pos->e_y = -1;
    return (pos);
}

int main(int argc, char **argv)
{
    int     fd;
    t_map   *map;
    t_mv    *pos;
    (void)argc;

    fd = open(argv[1], O_RDONLY);
    map = init_map();
    pos = init_mv();
    get_map(fd, map);
    afftab(map->map);
    audit(map, pos);
    free_tab(map->map);
    free(map);
    free(pos);
}