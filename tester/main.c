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
    pos->e_x = -1;
    pos->e_y = -1;
    return (pos);
}

void    afft_map(t_map *map)
{
    printf("Height  %i\n", map->height);
    printf("len     %i\n", map->len);
    printf("c init  %i\n", map->c_init);
    printf("c e     %i\n", map->c_e);
    printf("c p     %i\n", map->c_p);
    printf("c c     %i\n", map->c_c);
    printf("c b     %i\n", map->c_b);
    printf("c obl   %i\n", map->c_oblong);
    printf("c wall  %i\n", map->c_wall);
}

void    afft_mv(t_mv *pos, t_map *map)
{
    printf("x   %i\n", pos->x);
    printf("y   %i\n", pos->y);
    printf("tmp x   %i\n", pos->tmp_x);
    printf("tmp y   %i\n", pos->tmp_y);
    printf("case    %c\n", map->map[pos->y][pos->x]);
}

int main(int argc, char **argv)
{
    int fd;
    t_map   *map;
    t_mv    *pos;
    (void)argc;

    fd = open(argv[1], O_RDONLY);
    map = init_map();
    pos = init_mv();
    map->c_b = 0;
    get_map(fd, map);
    afftab(map->map);
    audit(map, pos);
    maj_map(map, pos, argv[2][0]);
    maj_map(map, pos, argv[2][0]);
    maj_map(map, pos, argv[2][0]);
    printf("\n");
    afftab(map->map);
    free(map);
}
