/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:49:55 by mlecherb          #+#    #+#             */
/*   Updated: 2022/03/29 18:30:34 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->len = 0;
	map->c_init = 0;
	map->c_e = 0;
	map->c_p = 0;
	map->c_c = 0;
	map->c_b = 0;
	map->c_oblong = 0;
	map->c_wall = 0;
	map->key = 0;
	return (map);
}

t_mv	*init_mv(void)
{
	t_mv	*pos;

	pos = malloc(sizeof(t_mv));
	pos->x = 0;
	pos->y = 0;
	pos->tmp_x = 0;
	pos->tmp_y = 0;
	pos->count = 1;
	pos->e_x = -1;
	pos->e_y = -1;
	return (pos);
}

int	ft_destroy_windows(t_vars *d)
{
	mlx_destroy_window(d->mlx, d->mlx_win);
	end_program("Closed");
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	vars.map = init_map();
	vars.pos = init_mv();
	get_map(fd, vars.map);
	audit(vars.map, vars.pos);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 640, 640, "so_long");
	vars.img.img = mlx_new_image(vars.mlx, 640, 640);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	det_case_x(vars.map, vars.pos);
	print_tab(vars.map->mini, &vars.img);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img.img, 0, 0);
	mlx_hook(vars.mlx_win, 17, 0, ft_destroy_windows, &vars);
	mlx_key_hook(vars.mlx_win, maj_map, &vars);
	mlx_loop(vars.mlx);
	free_all(&vars);
}
