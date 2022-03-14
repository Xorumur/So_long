#ifndef SO_LONG_H
# define SO_LONG_H

# include "../gnl/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 4096
# define ERROR_WALL "Error: Not 1 in all the border\n"
# define ERROR_OBLONG "Error: This is not an oblong\n"
# define ERROR_INIT "Error: There is not the require item in the map (E/C/P)\n"
# define GOT_CAUGHT "You lose\n"

typedef struct s_map
{
    char    **map;
    int     height;
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
    int     bot_y;
    int     bot_x;
    int     temp_x;
    int     temp_y;
    int     bot_e_x;
    int     bot_e_y;
    int     bot_c_x;
    int     bot_c_y;   
    char    tmp;
    int     tmp_x;
    int     tmp_y;
    int     e_x;
    int     e_y;
}   t_mv ;

void    get_map(int fd, t_map map);
void    audit(t_map map);
void	end_program(char *mess);
t_mv    init_mv(t_mv pos);
t_map   init_map(t_map map);
\
/*          lib         */
int     ft_atoi(char *str);
char    *ft_strdup(const char *s1);
int     ft_strlen(const char *str);
/*         map geb      */
void    write_first_line(int len, int fd);
void    rdm_line(int len, int fd);
void    write_top_bot(int len, int fd);
void    rdm_line_error(int fd, int len);
void    loop_rline(int i, int height, int fd, char *error_name);
void    gen_map(char **argv);
void    make_error(int fd, int len, int height, char *error_name);
/*          bot         */
int     random_number(int min_num, int max_num);
void    bot_mv(t_mv pos, t_map map);
int     audit_new_pos_bot(t_mv pos, t_map map);
void    maj_map_bot(t_map map, t_mv pos, int keybind);
\
#endif
