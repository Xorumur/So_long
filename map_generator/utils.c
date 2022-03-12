#include "../includes/so_long.h"

void    rdm_line_error(int fd, int len)
{
    int i;

    i = 0;
    write(fd, '0', 1);
    while (i <= len)
    {
        write(fd, '0', 1);
        i++;
    }
    write(fd, '0', 1);
    write(fd, '\n', 1);
}

void    loop_rline(int i, int height, int fd, char *error_name)
{
    if (error_name == "WALL")
    {
        while (i <= height - 3)
            rdm_line_error(len, fd);        
    }
    else if (error_name == "OBLONG")
    {
        while (i <= height - 3)
            rdm_line(i, fd);
    }
    else if (error_name == "INIT")
    {
        while (i <= height - 2)
            rdm_line(len, fd);
    }
}