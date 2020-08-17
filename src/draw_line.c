/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 21:53:09 by qdang             #+#    #+#             */
/*   Updated: 2020/08/16 17:50:49 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	draw_line_x(t_info *s, int x, int y, int color)
{
	int		i;
	double	k;

	i = -1;
	k = (double)(y - s->stand_y) / (double)(x - s->stand_x);
	if (x > s->stand_x)
		while (++i <= x - s->stand_x)
			mlx_pixel_put(s->mlx_ptr, s->win_ptr, s->stand_x + i,
				lround(s->stand_y + i * k), color);
	else
		while (++i <= s->stand_x - x)
			mlx_pixel_put(s->mlx_ptr, s->win_ptr, x + i,
				lround(y + i * k), color);
}

static void	draw_line_y(t_info *s, int x, int y, int color)
{
	int		i;
	double	k;

	i = -1;
	k = (double)(x - s->stand_x) / (double)(y - s->stand_y);
	if (y > s->stand_y)
		while (++i <= y - s->stand_y)
			mlx_pixel_put(s->mlx_ptr, s->win_ptr, lround(s->stand_x + i * k),
				s->stand_y + i, color);
	else
		while (++i <= s->stand_y - y)
			mlx_pixel_put(s->mlx_ptr, s->win_ptr, lround(x + i * k),
				y + i, color);
}

void		draw_line(t_info *s, int x, int y, int color)
{
	int		i;
	int		abs_x;
	int		abs_y;

	i = -1;
	abs_x = ft_abs(x - s->stand_x);
	abs_y = ft_abs(y - s->stand_y);
	if (abs_x == 0)
		while (++i <= abs_y)
			mlx_pixel_put(s->mlx_ptr, s->win_ptr,
				x, ft_min(y, s->stand_y) + i, color);
	else if (abs_y == 0)
		while (++i <= abs_x)
			mlx_pixel_put(s->mlx_ptr, s->win_ptr,
				ft_min(x, s->stand_x) + i, y, color);
	else
		abs_y <= abs_x ?
			draw_line_x(s, x, y, color) : draw_line_y(s, x, y, color);
}
