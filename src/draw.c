/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 14:53:54 by qdang             #+#    #+#             */
/*   Updated: 2020/07/29 08:48:02 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    draw_2d_block(t_info *s, int x, int y, int color)
{
    int     i;
    int     j;

    i = -1;
    while (++i < s->ul) 
    {
        j = -1;
        while (++j < s->ul)
            mlx_pixel_put(s->mlx_ptr, s->win_ptr, x + i, y + j, color);
    }
}
/*
void	intersect(t_info *s, int radian)
{
	tan(radian);
}
*/
/*
** (x, y) on the screen is in the reversed order of (x, y) stored in the map.
*/

void    draw_2d_map(t_info *s)
{
    int     i;
    int     j;

	mlx_clear_window(s->mlx_ptr, s->win_ptr);
    i = -1;
    while (++i < s->map_y)
    {
        j = -1;
        while (++j < s->map_x)
        {
            if (s->map[i][j] == '1')
                draw_2d_block(s, BEGIN_X + j * s->ul, BEGIN_Y + i * s->ul, WHITE);
            if (s->map[i][j] == '2')
                draw_2d_block(s, BEGIN_X + j * s->ul, BEGIN_Y + i * s->ul, YELLOW);
        }
    }
	s->stand_x = BEGIN_X + (s->start_x + s->move_x + 0.5) * s->ul;
	s->stand_y = BEGIN_Y + (s->start_y + s->move_y + 0.5) * s->ul;
	mlx_pixel_put(s->mlx_ptr, s->win_ptr, s->stand_x, s->stand_y, RED);
	i = -1;
	while (++i <= 50)
		draw_line(s, 250, 200 + i, RED);
}
