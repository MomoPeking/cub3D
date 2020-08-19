/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdang <qdang@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 21:53:09 by qdang             #+#    #+#             */
/*   Updated: 2020/08/18 23:04:16 by qdang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	draw_line_x(t_info *s, t_point p1, t_point p2, int color)
{
	int		i;
	double	k;

	i = -1;
	k = (double)(p2.y - p1.y) / (double)(p2.x - p1.x);
	if (p2.x > p1.x)
		while (++i <= p2.x - p1.x)
			mlx_pixel_put(s->mlx_ptr, s->win_ptr, p1.x + i,
				lround(p1.y + i * k), color);
	else
		while (++i <= p1.x - p2.x)
			mlx_pixel_put(s->mlx_ptr, s->win_ptr, p2.x + i,
				lround(p2.y + i * k), color);
}

static void	draw_line_y(t_info *s, t_point p1, t_point p2, int color)
{
	int		i;
	double	k;

	i = -1;
	k = (double)(p2.x - p1.x) / (double)(p2.y - p1.y);
	if (p2.y > p1.y)
		while (++i <= p2.y - p1.y)
			mlx_pixel_put(s->mlx_ptr, s->win_ptr, lround(p1.x + i * k),
				p1.y + i, color);
	else
		while (++i <= p1.y - p2.y)
			mlx_pixel_put(s->mlx_ptr, s->win_ptr, lround(p2.x + i * k),
				p2.y + i, color);
}

/*
** draw_line is a function to draw a line from (stand_x, stand_y) to (x, y).
*/

void		draw_line(t_info *s, t_point p1, t_point p2, int color)
{
	int		i;
	int		abs_x;
	int		abs_y;

	i = -1;
	abs_x = ft_abs(p2.x - p1.x);
	abs_y = ft_abs(p2.y - p1.y);
	if (abs_x == 0)
		while (++i <= abs_y)
			mlx_pixel_put(s->mlx_ptr, s->win_ptr,
				p2.x, ft_min(p2.y, p1.y) + i, color);
	else if (abs_y == 0)
		while (++i <= abs_x)
			mlx_pixel_put(s->mlx_ptr, s->win_ptr,
				ft_min(p2.x, p1.x) + i, p2.y, color);
	else
		abs_y <= abs_x ?
			draw_line_x(s, p1, p2, color) : draw_line_y(s, p1, p2, color);
}
