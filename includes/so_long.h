#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "ft_printf-42/ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 4096
# define ERROR_WALL "Error: Not 1 in all the border"
# define ERROR_OBLONG "Error: This is not an oblong"
# define ERROR_INIT "Error: There is not the require item in the map (E/C/P)"

typedef struct s_map
{
    char    **map;
    int     len;
    int     c_init;
    int     c_e;
    int     c_p;
    int     c_c;
    int     c_oblong;
    int     c_wall;
}   t_map;

typedef struct s_mv
{
    int     x;
    int     y;
    char    tmp;
    int     tmp_x;
    int     tmp_y;
}   t_mv ;

void    get_map(int fd, t_map map);
void    audit(t_map map);
void	end_program(char *mess);
char    *ft_strdup(const char *s1);
t_mv    init_mv(t_mv pos);
t_map   init_map(t_map map);
\
#endif
