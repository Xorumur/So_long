#include "../includes/so_long.h"

void    maj_map(t_map map, char keybind)
{
    t_mv pos;

    pos = init_mv(pos);
    //Mettre les pos de depart
    if (keybind == 'W')
        pos.tmp_y += 1;
    else if (keybind == 'A')
        pos.tmp_x -= 1;
    else if (keybind == 'S')
        pos.tmp_y -= 1;
    else if (keybind == 'D')
        pos.tmp_x += 1;
    audit_new_pos(pos, map);
}

void    audit_new_pos(t_mv pos, t_map map)
{

}
