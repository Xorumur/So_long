/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:03:29 by mlecherb          #+#    #+#             */
/*   Updated: 2022/03/29 19:08:56 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_map(int fd, t_map *map)
{
	char	buf[2];
	int		len;
	char	*line;

	len = read(fd, buf, 1);
	buf[1] = '\0';
	line = ft_strdup(buf);
	len = read(fd, buf, 1);
	buf[1] = '\0';
	while (len > 0)
	{
		line = ft_strjoin_g(line, buf);
		len = read(fd, buf, 1);
		buf[1] = '\0';
	}
	map->map = ft_split(line, '\n');
	free(line);
}

static void	border_analyzer(t_map *map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	len = map->len - 1;
	i = 0;
	while (map->map[i])
	{
		len = ft_strlen(map->map[i]) - 1;
		if (map->map[i][0] != '1' || map->map[i][len] != '1')
			end_program(ERROR_WALL);
		i++;
	}
	map->c_wall = 1;
}

static void	charac_analizer(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (line[i] != 13 && line[i])
	{
		if (line[i] == 'C')
			map->c_c += 1;
		else if (line[i] == 'P' && map->c_p == 1)
			line[i] = '0';
		else if (line[i] == 'B' && map->c_b == 1)
			line[i] = '0';
		else if (line[i] == 'P')
			map->c_p = 1;
		else if (line[i] == 'E')
			map->c_e = 1;
		else if (line[i] == 'B')
			map->c_b = 1;
		else if (line[i] != '0' && line[i] != '1')
			end_program(ERROR_BAD_CHAR);
		i++;
	}
}

void	audit(t_map *map, t_mv *pos)
{
	int	i;

	i = 0;
	map->len = ft_strlen(map->map[i]);
	while (map->map[i])
	{
		init_pos(pos, map, map->map[i], i);
		charac_analizer(map, map->map[i]);
		if ((ft_strlen(map->map[i])) != map->len)
			end_program(ERROR_OBLONG);
		i++;
	}
	map->height = i;
	border_analyzer(map);
	map->c_oblong = 1;
	if (map->len == i)
		end_program(ERROR_OBLONG);
	if (map->c_e == 1 && map->c_p == 1 && map->c_c > 0)
		map->c_init = 1;
	if (map->c_init != 1)
		end_program(ERROR_INIT);
}
