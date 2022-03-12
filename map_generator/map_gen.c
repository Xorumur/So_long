#include "../includes/so_long.h"

void    write_top_bot(int len, int fd)
{
    int i;

    i = 0;
    while (i <= len)
    {
        write(fd, '1', 1);
        i++;
    }
    write(fd, '\n', 1);
}

void    rdm_line(int len, int fd)
{
    int i;

    i = 0;
    write(fd, '1', 1);
    while (i <= len - 2)
    {
        write(fd, '0', 1);
        i++;
    }
    write(fd, '1', 1);
    write(fd, '\n', 1);
}

void    write_first_line(int len, int fd)
{
    int i;

    i = 0;
    write(fd, '1', 1);
    write(fd, 'P', 1);
    write(fd, 'C', 1);
    write(fd, 'E', 1);
    while (i <= len - 5)
    {
        write(fd, '0', 1);
        i++;
    }
    write(fd, '1', 1);
    write(fd, '\n', 1);
}

void    make_error(int fd, int len, int height, char *error_name)
{
    int     i;

    i = 0;
    if (error_name == "WALL")
    {
        write_top_bot(len, fd);
        write_first_line(len, fd);
        loop_rline(i, height, fd, error_name);
        write_top_bot(len, fd);
    }
    else if (error_name == "OBLONG")
    {
        write_top_bot(len, fd);
        write_first_line(len, fd);
        loop_rline(i, height, fd, error_name);
        write_top_bot(len, fd);
    }
    else if (error_name == "INIT")
    {
        write_top_bot(len, fd);
        loop_rline(i, height, fd, error_name);
        write_top_bot(len, fd);
    }
}

void    gen_map(char **argv)
/* Ne prend aps en compte les petites maps pas de checker non plus */
{
    int len;
    int height;
    int i;
    int fd;

    i = 0;
    height = ft_atoi(argv[3]);
    len = ft_atoi(argv[2]);
    fd = open(arv[1], O_TRUNC | O_CREAT | O_RDWR, 0644);
    if (argv[4] == "true")
    {
        write_top_bot(len, fd);
        write_first_line(len, fd);
        while (i <= height - 3)
            rdm_line(len, fd);
        write_top_bot(len, fd);
    }
    else 
    {   
        make_error(fd, len, argv[6]);
    }
}