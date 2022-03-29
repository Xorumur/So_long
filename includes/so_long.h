#ifndef SO_LONG_H
# define SO_LONG_H

// # include "../gnl/get_next_line.h"
# include "../includes/so_long_bonus.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>

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
    int     count;
}   t_mv;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct  x_cordo {
    int     x;
    int     y;
}   t_cordo;

typedef struct s_vars {
    void    *mlx;
    void    *mlx_win;
    t_mv    *pos;
    t_map   *map;
    t_data  img;
    t_cordo *posi;
}   t_vars;

void    get_map(int fd, t_map *map);
void    audit(t_map *map, t_mv *pos); //void    audit(t_map map, t_mv pos);
void	end_program(char *mess);
void    init_pos(t_mv *pos, t_map *map, char *line, int y);
int     maj_map(int keybind, t_vars *vars);
void    tmp_pos(t_mv *pos, int x, int y);
void    reattrib_pos(t_mv *pos, int x, int y);
void    det_case_x(t_map *m, t_mv *p);
void    det_case_y(t_map *m, t_mv *p, int x);
void    ajust(t_map *map, t_mv *pos, int x, int y);
char    *str_cut(char *dst, char *src, int  start, int end, t_map *map);
void    free_all(t_vars *vars);
void    free_tab(char **tab);
\
/*          lib         */
int     ft_atoi(char *str);
char    *ft_strdup(char *s1);
int     ft_strlen(char *str);
char	*ft_strjoin_g(char *s1, char *s2);
char	**ft_split(char *s, char c);
void	ft_putnbr(int nb);
/*          tester      */
void    afftab(char **map);
void    ft_putstr(char *str);
void    afft_map(t_map *map);
void    afft_mv(t_mv *pos, t_map *map);
/*          MLX         */
void    print_tab(char  **tab, t_data *data);
void    det_car(char c, t_data *data, int x, int y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    print_square(t_data *data, int x, int y, int color);

\
#endif
