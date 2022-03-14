#include "../includes/so_long.h"

void    maj_map_bot(t_map map, t_mv pos, int keybind)
{
    if (keybind == 1)
        pos.temp_y = pos.bot_y + 1;
    else if (keybind == 2)
        pos.temp_x -= pos.bot_x - 1;
    else if (keybind == 3)
        pos.temp_y = pos.bot_y - 1;
    else if (keybind == 4)
        pos.temp_x = pos.bot_x + 1;
}

int     audit_new_pos_bot(t_mv pos, t_map map)
{
    if (map.map[pos.temp_y][pos.temp_x] == '1' 
        || map.map[pos.temp_y][pos.temp_x] == 'C' 
        || map.map[pos.temp_y][pos.temp_x] == 'E')
        return (0);
    else if (map.map[pos.temp_y][pos.temp_x] == '0')
    {
        pos.bot_x = pos.temp_x;
        pos.bot_y = pos.temp_y;
        return (1);
    }
    else if (map.map[pos.temp_y][pos.temp_x] == 'P')
        end_program(GOT_CAUGHT);
    else 
        return (0);
}

void    bot_mv(t_mv pos, t_map map)
{
    int     rdm;

    rdm = random_number(1,4);
    maj_map_bot(map, pos, rdm);   
    map.map[pos.bot_y][pos.bot_x] = '0';
    while (audit_new_pos_bot(pos, map) == 0)
    {
        rdm = random_number(1,4);
        maj_map_bot(map, pos, rdm);
    }
    map.map[pos.bot_y][pos.bot_x] == 'B';
}

int random_number(int min_num, int max_num)
{
    int result = 0;
    int low_num = 0;
    int hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } 
    else
    {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }
    
    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}
