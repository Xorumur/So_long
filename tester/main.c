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
    return (map);
}

int main(int argc, char ** argv)
{
    // int fd;
    t_map *map;
    (void)argc;

    printf("O\n");
    int fd = open(argv[1], O_RDONLY);
    printf("%i\n", fd);
    map = init_map();
    printf("%i\n", fd);
    get_map(fd, map);
    // afftab(map.map);
}
