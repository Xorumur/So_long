#include "../includes/so_long.h"

static void full_init(t_map *map, t_mv *pos, int fd)
{
    map = init_map();
    pos = init_mv();
    get_map(fd, map);
    audit(map, pos);
}

int main(int argc, char **argv) // Prototype du main
{
    int fd;
    t_map   *map;
    t_mv    *pos;
    (void)argc;

    fd = open(argv[1], O_RDONLY);
    full_init(map, pos, fd);
    affmap(map); // AFFICHER LA MAP
    while (/*ATTENDRE UN NOUVEAU MVT*/)
    {
        maj_map(map, pos, "La keybind"); // Mis a jour de la map avec le mouvement fait.
        if (/*check si la map est trop grande pour l affichage*/)
        {
            ajust(map, pos); 
    // Ici il ne manque plus de savoir les dimensions max capable d'afficher de la fenetre
            affmap(map->mini);
        }
        else 
            affmap(map->map);
    }
    free(/*Tout ce qui a été malloc*/);
    free(map);
}

