/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:16:27 by mlecherb          #+#    #+#             */
/*   Updated: 2022/03/29 18:24:33 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	tmp_pos(t_mv *pos, int x, int y)
{
	pos->tmp_y = y;
	pos->tmp_x = x;
}

void	reattrib_pos(t_mv *pos, int x, int y)
{
	pos->x = x;
	pos->y = y;
}

static void	map_replace(t_mv *pos, t_map *map)
{
	char	new;

	new = map->map[pos->tmp_y][pos->tmp_x];
	if (pos->e_x > 0 && pos->e_y > 0)
	{
		map->map[pos->y][pos->x] = 'E';
		if (map->map[pos->tmp_y][pos->tmp_x] != '1')
		{
			pos->e_x = -1;
			pos->e_y = -1;
		}
	}
	else
		map->map[pos->y][pos->x] = '0';
	if (new == 'E' || new == '0' || new == 'C')
		pos->count++;
}

static void	audit_new_pos(t_mv *pos, t_map *map)
{
	if (map->map[pos->tmp_y][pos->tmp_x] == '1')
		return ;
	else if (map->map[pos->tmp_y][pos->tmp_x] == 'C')
	{
		map->c_c -= 1;
		reattrib_pos(pos, pos->tmp_x, pos->tmp_y);
	}
	else if (map->map[pos->tmp_y][pos->tmp_x] == '0')
		reattrib_pos(pos, pos->tmp_x, pos->tmp_y);
	else if (map->map[pos->tmp_y][pos->tmp_x] == 'E')
	{
		if (map->c_c == 0)
			end_program(WIN);
		pos->e_x = pos->tmp_x;
		pos->e_y = pos->tmp_y;
		reattrib_pos(pos, pos->tmp_x, pos->tmp_y);
	}
}

int	maj_map(int keybind, t_vars *vars)
{
	if (keybind == 13)
		tmp_pos(vars->pos, vars->pos->x, (vars->pos->y - 1));
	else if (keybind == 0)
		tmp_pos(vars->pos, (vars->pos->x - 1), vars->pos->y);
	else if (keybind == 1)
		tmp_pos(vars->pos, vars->pos->x, (vars->pos->y + 1));
	else if (keybind == 2)
		tmp_pos(vars->pos, (vars->pos->x + 1), vars->pos->y);
	else if (keybind == 53)
		end_program("Escape");
	ft_putnbr(vars->pos->count);
	write(1, "\n", 1);
	map_replace(vars->pos, vars->map);
	audit_new_pos(vars->pos, vars->map);
	vars->map->map[vars->pos->y][vars->pos->x] = 'P';
	free_tab(vars->map->mini);
	det_case_x(vars->map, vars->pos);
	print_tab(vars->map->mini, &vars->img);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img.img, 0, 0);
	return (0);
}
