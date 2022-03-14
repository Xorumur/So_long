#include "includes/so_long.h"

int main(int argc, char **argv)
{
    t_map map;
    t_mv pos;
    int fd;

    fd = open(argv[1]);
    get_map(fd, map);
    audit(map, pos);
}