#include "../includes/so_long.h"

t_map init_map(t_map map)
{
   map.len = 0;
   map.c_init = 0;
   map.c_e = 0;
   map.c_p = 0;
   map.c_c = 0;
   map.c_oblong = 0;
   map.c_wall = 0;
   return (map);
}

t_mv    init_mv(t_mv pos)
{
    pos.x = 0;
    pos.y = 0;
    pos.tmp_x = 0;
    pos.tmp_y = 0;
    pos.e_x = -1;
    pos.e_y = -1;
    return (pos);
}