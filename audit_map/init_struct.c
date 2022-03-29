/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:09:26 by mlecherb          #+#    #+#             */
/*   Updated: 2022/03/29 19:11:04 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_pos(t_mv *pos, t_map *map, char *line, int y)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i])
	{
		if (line[i] == 'P' && map->c_p == 0)
		{
			pos->x = i;
			pos->y = y;
		}
		if (line[i] == 'B' && map->c_b == 0)
		{
			pos->bot_x = i;
			pos->bot_y = y;
		}
		i++;
	}
}
