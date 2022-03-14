#include "../includes/so_long.h"

void    maj_map(t_map map, t_mv pos, char keybind)
{
    if (keybind == 'W')
        pos.tmp_y = pos.y + 1;
    else if (keybind == 'A')
        pos.tmp_x -= pos.x - 1;
    else if (keybind == 'S')
        pos.tmp_y = pos.y - 1;
    else if (keybind == 'D')
        pos.tmp_x = pos.x + 1;
    map_replace(pos, map);
    bot_mv(pos, map);
    audit_new_pos(pos, map);
    map.map[pos.y][pos.x] = 'P';
}

void    map_replace(t_mv pos, t_map map)
{   
    if (pos.e_x > 0 && pos.e_y > 0)
        map.map[pos.y][pos.x] = 'E';
    else 
        map.map[pos.y][pos.x] = '0';
    pos.e_x = -1;
    pos.e_y = -1;    
}

void    audit_new_pos(t_mv pos, t_map map)
{
    if (map.map[pos.tmp_y][pos.tmp_x] == '1')
        return ;
    else if (map.map[pos.tmp_y][pos.tmp_x] == 'C')
    {
        map.c_c -= 1;
        pos.x = pos.tmp_x;
        pos.y = pos.tmp_y;
    }
    else if (map.map[pos.tmp_y][pos.tmp_x] == '0')
    {
        pos.x = pos.tmp_x;
        pos.y = pos.tmp_y;
    }
    else if (map.map[pos.tmp_y][pos.tmp_x] == 'E')
    {
        pos.e_x = pos.tmp_x;
        pos.e_y = pos.tmp_y;
        pos.x = pos.tmp_x;
        pos.y = pos.tmp_y;        
    }
    else if (pos.tmp_y == pos.bot_y && pos.tmp_x == pos.bot_x)
        end_program(GOT_CAUGHT);
}

