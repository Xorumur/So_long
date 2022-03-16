#ifndef SO_LONG_H
# define SO_LONG_H

# include "../gnl/get_next_line.h"
# include "../includes/so_long_bonus.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 4096
# define ERROR_WALL "Error: Not 1 in all the border\n"
# define ERROR_OBLONG "Error: This is not an oblong\n"
# define ERROR_INIT "Error: There is not the require item in the map (E/C/P)\n"
# define ERROR_BAD_CHAR "Error: There is another character than E/C/P/0/1\n"
# define GOT_CAUGHT "You lose\n"
# define WIN "You win\n"

typedef struct s_map
{
    char    **map;
    char    **mini;
    int     height;
    int     len;
    int     c_init;
    int     c_e;
    int     c_p;
    int     c_c;
    int     c_b;
    int     c_oblong;
    int     c_wall;
    int     key;
}   t_map;

typedef struct s_mv
{
    int     x;
    int     y;
    int     bot_y;
    int     bot_x;
    int     temp_x;
    int     temp_y;
    int     bot_c_x;
    int     bot_c_y;   
    char    tmp;
    int     tmp_x;
    int     tmp_y;
    int     e_x;
    int     e_y;
}   t_mv;

void    get_map(int fd, t_map *map);
void    audit(t_map *map, t_mv *pos); //void    audit(t_map map, t_mv pos);
void	end_program(char *mess);
t_mv    *init_mv(void);
t_map   *init_map(void);
void    init_pos(t_mv *pos, t_map *map, char *line, int y);
void    maj_map(t_map *map, t_mv *pos, char keybind);
void    map_replace(t_mv *pos, t_map *map);
void    audit_new_pos(t_mv *pos, t_map *map);
void    tmp_pos(t_mv *pos, int x, int y);
void    tmp_pos_bot(t_mv *pos, int x, int y);
void    ajust(t_map *map, t_mv *pos);
char    *str_cut(char *dst, char *src, int  start, int end, t_map *map);
\
/*          lib         */
int     ft_atoi(char *str);
char    *ft_strdup(char *s1);
int     ft_strlen(char *str);
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
void    bot_mv(t_mv *pos, t_map *map);
int     audit_new_pos_bot(t_mv *pos, t_map *map);
void    maj_map_bot(t_mv *pos, int keybind);
/*          tester      */
void    afftab(char **map);
void    ft_putstr(char *str);
void    afft_map(t_map *map);
void    afft_mv(t_mv *pos, t_map *map);
\
#endif
