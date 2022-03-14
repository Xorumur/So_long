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

int main(int argc, char ** argv)
{
    int fd;
    t_map *map;
    (void)argc;

    fd = open(argv[1], O_RDONLY);
    map = init_map();
    get_map(fd, map); 
    afftab(map->map);
    audit(map);
    free(map);
}