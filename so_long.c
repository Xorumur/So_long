#include "includes/so_long.h"

int main(int argc, char **argv)
{
    t_map map;
    int fd;

    fd = open(argv[1]);
    get_map(fd, map);
    audit(map);
}