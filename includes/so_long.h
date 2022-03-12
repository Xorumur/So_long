#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
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
t_mv    init_mv(t_mv pos);
t_map   init_map(t_map map);
\
/*          lib         */
int     ft_atoi(char *str)
char    *ft_strdup(const char *s1);
int     ft_strlen(const char *str)
/*         map geb      */
void    write_first_line(int len, int fd);
void    rdm_line(int len, int fd);
void    write_top_bot(int len, int fd);
void    rdm_line_error(int fd, int len);
void    loop_rline(int i, int height, int fd, char *error_name);
void    gen_map(char **argv)
void    make_error(int fd, int len, int height, char *error_name)
\
#endif
