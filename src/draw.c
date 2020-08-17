/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 14:53:54 by qdang             #+#    #+#             */
/*   Updated: 2020/08/16 17:59:29 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** The block include the upper and left edges but not the lower and right edges.
*/

static void	draw_2d_block(t_info *s, int x, int y, int color)
{
	int		i;
	int		j;

	i = -1;
	while (++i < UL)
	{
		j = -1;
		while (++j < UL)
			mlx_pixel_put(s->mlx_ptr, s->win_ptr, x + i, y + j, color);
	}
}

static void	draw_2d_frame(t_info *s)
{
	int		i;
	int		j;

	i = -1;
	while (++i < s->map_y)
	{
		j = -1;
		while (++j < s->map_x)
		{
			if (s->map[i][j] == '1')
				draw_2d_block(s, BEGIN_X + j * UL, BEGIN_Y + i * UL, WHITE);
			if (s->map[i][j] == '2')
				draw_2d_block(s, BEGIN_X + j * UL, BEGIN_Y + i * UL, YELLOW);
		}
	}
}

/*
** (x, y) on the screen is in the reversed order of (x, y) stored in the map.
*/

void		draw_2d_map(t_info *s)
{
	int		i;

	mlx_clear_window(s->mlx_ptr, s->win_ptr);
	s->grid_x = s->start_x + s->move_x;
	s->grid_y = s->start_y + s->move_y;
	s->stand_x = BEGIN_X + (s->grid_x + 0.5) * UL;
	s->stand_y = BEGIN_Y + (s->grid_y + 0.5) * UL;
	i = -1;
	while (++i <= PREC)
	{
		calc_its(s, (double)(s->start_sight + i * (M_PI / 180 * FOV) / PREC));
		draw_line(s, s->its_x, s->its_y, LIME);
	}
	draw_2d_frame(s);
}
