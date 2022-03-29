/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlecherb <mlecherb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:19:01 by mlecherb          #+#    #+#             */
/*   Updated: 2022/03/29 17:41:03 by mlecherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    print_square(t_data *img, int x, int y, int color)
{
    int tmp_x;
    int tmp_y;

    tmp_y = y;
    tmp_x = x;
    while (y < tmp_y + 32)
    {
        while (x < tmp_x + 32)
        {
            my_mlx_pixel_put(img, x, y, color);
            x++;
        }
        x = tmp_x;
        y++;
    }
}

void    det_car(char c, t_data *img, int x, int y)
{
    if (c == '1')
        print_square(img, x, y, 0x1C4AC5);
    else if (c == '0')
        print_square(img, x, y, 0xFFFFFF);
    else if (c == 'C')
        print_square(img, x, y, 0x2CDE37);
    else if (c == 'P')
        print_square(img, x, y, 0xF03F3F);
    else if (c == 'E')
        print_square(img, x, y, 0xE9F056);
}

t_cordo *init_position(void)
{
    t_cordo *pos;
    
    pos = malloc(sizeof(t_cordo));
    pos->x = 0;
    pos->y = 0;
    return (pos);

}

void    print_tab(char  **tab, t_data *img)
{
    int     i;
    int     j;
    t_cordo *posi;

    posi = init_position();
    i = 0;
    j = 0;
    while (tab[i] && i * 32 < 640)
    {
        while (tab[i][j] && j * 32 < 640)
        {
            det_car(tab[i][j], img, posi->x, posi->y);
            j++;
            posi->x += 32;
        }
        posi->x = 0;
        posi->y += 32;
        j = 0;
        i++;
    }
    free(posi);
}